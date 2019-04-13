// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file tester.hpp
 *
 * @brief Unit testing mini-library
 *
 * A single-header, small library for unit testing.
 */


#ifndef CYNODELIC_TESTER_HPP
#define CYNODELIC_TESTER_HPP


// ********** Configuration **********


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#define CYNODELIC_TESTER_STRINGIZE_IMPL(x) #x
#define CYNODELIC_TESTER_STRINGIZE(x) CYNODELIC_TESTER_STRINGIZE_IMPL(x)


#if defined(_WIN32) || defined(_WIN64)
#	define CYNODELIC_TESTER_OS_WINDOWS
#elif defined(__linux__)
#	define CYNODELIC_TESTER_OS_LINUX
#elif defined(__APPLE__) || defined(__MACH__)
#	define CYNODELIC_TESTER_OS_MAC
#endif


#ifdef __MSVC__
#	define CYNODELIC_TESTER_ALWAYS_INLINE __forceinline
#else
#	define CYNODELIC_TESTER_ALWAYS_INLINE __attribute__((always_inline))
#endif

#endif // DOXYGEN_SHOULD_SKIP_THIS


#define CYNODELIC_TESTER_VERSION_MAJOR 0  /**< @brief Major version of this library. */
#define CYNODELIC_TESTER_VERSION_MINOR 7  /**< @brief Minor version of this library. */
#define CYNODELIC_TESTER_VERSION_PATCH 0  /**< @brief Patch version of this library. */


/// @brief The version of this library
#define CYNODELIC_TESTER_VERSION CYNODELIC_TESTER_STRINGIZE(CYNODELIC_TESTER_VERSION_MAJOR) "." CYNODELIC_TESTER_STRINGIZE(CYNODELIC_TESTER_VERSION_MINOR) "." CYNODELIC_TESTER_STRINGIZE(CYNODELIC_TESTER_VERSION_PATCH)


#ifndef CYNODELIC_TESTER_CLOCK_TYPE

/**
 * @brief Macro for clock type
 *
 * Defines the clock type used by this library, like the ones from the
 * `<chrono>` standard header. For using another clock type, define this macro
 * before this header file.
 */
#define CYNODELIC_TESTER_CLOCK_TYPE ::std::chrono::steady_clock
#endif // CYNODELIC_TESTER_CLOCK_TYPE


#ifndef CYNODELIC_TESTER_RANDOM_NUMBER_ENGINE

/**
 * @brief Macro for pseudorandom number engine
 *
 * Defines the pseudorandom number engine type used by this library, like the
 * ones from the `<random>` standard header. For using another engine, define
 * this macro before this header file.
 */
#define CYNODELIC_TESTER_RANDOM_NUMBER_ENGINE ::std::mt19937
#endif // CYNODELIC_TESTER_RANDOM_NUMBER_ENGINE


#ifndef DOXYGEN_SHOULD_SKIP_THIS

#if defined(CYNODELIC_TESTER_OS_LINUX) || defined(CYNODELIC_TESTER_OS_MAC)
#define CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(modname,win_params,unix_params) \
struct modname \
{ \
	modname() = default; \
	static bool& is_enabled_() \
	{ \
		static bool val_; \
		return val_; \
	} \
	static void enable(const bool& enabled) \
	{ \
		is_enabled_() = enabled; \
	} \
	template <typename CharT,typename Traits> \
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const modname&) \
	{ \
		if (is_enabled_()) \
		{ \
			os << unix_params; \
		} \
		return os; \
	} \
}
#elif defined(CYNODELIC_TESTER_OS_WINDOWS)
#define CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(modname,win_params,unix_params) \
struct modname \
{ \
	modname() = default; \
	static bool& is_enabled_() \
	{ \
		static bool val_; \
		return val_; \
	} \
	static void enable(const bool& enabled) \
	{ \
		is_enabled_() = enabled; \
	} \
	template <typename CharT,typename Traits> \
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const modname&) \
	{ \
		if (is_enabled_()) \
		{ \
			SetConsoleTextAttribute(detail::hconsole::get(),win_params); \
		} \
		return os; \
	} \
}
#else
#define CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(modname,win_params,unix_params) \
struct modname \
{ \
	modname() = default; \
	static bool& is_enabled_() \
	{ \
		static bool val_; \
		return val_; \
	} \
	static void enable(const bool& enabled) \
	{ \
		is_enabled_() = enabled; \
	} \
	template <typename CharT,typename Traits> \
	friend std::basic_ostream<CharT,Traits>& operator<<(std::basic_ostream<CharT,Traits>& os,const modname&) \
	{ \
		return os; \
	} \
}
#endif

#endif // DOXYGEN_SHOULD_SKIP_THIS 


// ********** Types and functions **********


#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <ratio>
#include <functional>
#include <chrono>
#include <memory>

#ifdef CYNODELIC_TESTER_OS_WINDOWS
#include <windows.h>
#endif


namespace cynodelic { namespace tester {


/**
 * @brief Alias for the clock type used.
 */
using clock_type = CYNODELIC_TESTER_CLOCK_TYPE;


/**
 * @brief Alias for the clock time point type.
 */
using clock_time_point = std::chrono::time_point<clock_type>;


/**
 * @brief Alias for the duration type used by the clock.
 */
using clock_duration_type = typename clock_time_point::duration;


/**
 * @brief Alias for the pseudorandom number engine used.
 */
using random_engine = CYNODELIC_TESTER_RANDOM_NUMBER_ENGINE;


/**
 * @brief Exit status for the `run_tests` function.
 */
enum class test_exit_status
{
	exec_failure, /**< @brief Failure during execution, not related to the tests */
	exec_success, /**< @brief Execution with no errors */
	test_failure, /**< @brief At least one of the tests failed */
	test_success  /**< @brief All tests passed */
};


/**
 * @brief Enumerator for the results of test checkings
 */
enum class check_status
{
	passed,          /**< @brief The test check passed */
	failed_warning,  /**< @brief Warning */
	failed_check,    /**< @brief The check failed */
	failed_assertion /**< @brief The check failed with the abortion of the test case */
};


/**
 * @brief Type for `newline`
 */
class newline_t
{
	public:
		constexpr newline_t() = default;
};


/**
 * @brief Adds a new line
 *
 * A modifier that adds new lines in the error messages for
 * `CYNODELIC_TESTER_{CHECK,WARN,ASSERT}_*`, as well as in
 * @ref CYNODELIC_TESTER_MESSAGE.
 */
constexpr newline_t newline;



#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace detail
{
	template <check_status Value>
	struct as_tag {};


	/**
	 * @brief Holds stream inputs
	 */
	class input_holder
	{
		public:
			enum class iph_flag
			{
				is_string,
				is_newline
			};

			input_holder() = default;

			input_holder(const std::string& str)
			{
				str_ptr = std::make_unique<std::string>(str);
				iphf    = iph_flag::is_string;
			}

			input_holder(const newline_t&)
			{
				str_ptr.reset(nullptr);
				iphf = iph_flag::is_newline;
			}

			input_holder(const input_holder& other)
			{
				iphf = other.iphf;

				switch (iphf)
				{
					case iph_flag::is_string:
						str_ptr = std::make_unique<std::string>(*other.str_ptr);
						break;
					case iph_flag::is_newline:
						str_ptr.reset(nullptr);
						break;
				}
			}

			input_holder& operator=(const std::string& str)
			{
				str_ptr = std::make_unique<std::string>(str);
				iphf    = iph_flag::is_string;

				return *this;
			}

			input_holder& operator=(const newline_t&)
			{
				str_ptr.reset(nullptr);
				iphf = iph_flag::is_newline;

				return *this;
			}

			input_holder& operator=(const input_holder& other)
			{
				iphf = other.iphf;

				switch (iphf)
				{
					case iph_flag::is_string:
						str_ptr = std::make_unique<std::string>(*other.str_ptr);
						break;
					case iph_flag::is_newline:
						str_ptr.reset(nullptr);
						break;
				}

				return *this;
			}

			iph_flag get_flag() const
			{
				return iphf;
			}

			std::string get_str() const
			{
				if (iphf != iph_flag::is_string)
				{
					throw std::logic_error("Not a valid type for a string.");
				}

				return *str_ptr;
			}
		private:
			std::unique_ptr<std::string> str_ptr;
			iph_flag                     iphf;
	};


	/**
	 * @brief Contains information about a test check
	 */
	struct test_check_result_holder
	{
		std::string         file_name;
		std::string         section_name;
		std::string         check_str;
		std::size_t         line_num;
		clock_duration_type test_time;
		check_status        chk_status;

		test_check_result_holder() = default;

		test_check_result_holder(
			const std::string&         fname,
			const std::string&         mth_name,
			const std::string&         chk_str,
			const std::size_t&         line_n,
			const clock_duration_type& test_tm,
			const check_status&        status
		) :
			file_name(fname),
			section_name(mth_name),
			check_str(chk_str),
			line_num(line_n),
			test_time(test_tm),
			chk_status(status)
		{}

		test_check_result_holder(
			const test_check_result_holder& other
		) :
			file_name(other.file_name),
			section_name(other.section_name),
			check_str(other.check_str),
			line_num(other.line_num),
			test_time(other.test_time),
			chk_status(other.chk_status)
		{}

		test_check_result_holder& operator=(const test_check_result_holder& other)
		{
			file_name    = other.file_name;
			section_name = other.section_name;
			check_str    = other.check_str;
			line_num     = other.line_num;
			test_time    = other.test_time;
			chk_status   = other.chk_status;

			return *this;
		}
	};


	/**
	 * @brief Contains information about a test case
	 */
	struct test_case_result_holder
	{
		std::string                           case_name;
		clock_duration_type                   test_time;
		std::size_t                           num_tests;
		std::size_t                           num_passed;
		std::size_t                           num_failed;
		std::vector<test_check_result_holder> tcase_check_results;
		check_status                          case_status;

		test_case_result_holder() = default;

		test_case_result_holder(
			const std::string&                           case_nm,
			const clock_duration_type&                   test_tm,
			const std::size_t&                           num_tts,
			const std::size_t&                           num_pssd,
			const std::size_t&                           num_fld,
			const std::vector<test_check_result_holder>& tcase_check_res,
			const check_status&                          status
		) :
			case_name(case_nm),
			test_time(test_tm),
			num_tests(num_tts),
			num_passed(num_pssd),
			num_failed(num_fld),
			tcase_check_results(tcase_check_res),
			case_status(status)
		{}
	};


	/**
	 * @brief Holds the corresponding function of a test case
	 */
	struct test_case_holder
	{
		using method_type = std::function<test_case_result_holder(const bool&,const char&,const char&)>;

		std::string case_name;
		method_type case_function;
		std::string long_flag;
		std::string short_flag;

		test_case_holder(
			const std::string& case_nm,
			const method_type& case_fn
		) :
			case_name(case_nm),
			case_function(case_fn)
		{
			long_flag  = std::string("--run_") + case_name;
			short_flag = std::string("-r_") + case_name;
		}

		test_case_result_holder operator()(const bool& quiet,const char& show_fl,const char& show_tm)
		{
			return case_function(quiet,show_fl,show_tm);
		}
	};


	/**
	 * @brief Holds the corresponding function of a test method
	 */
	struct test_section_holder
	{
		using method_type = std::function<void()>;

		std::string case_name;
		std::string section_name;
		method_type case_method;

		test_section_holder(
			const std::string& case_nm,
			const std::string& mth_nm,
			const method_type& case_mth
		) :
			case_name(case_nm),
			section_name(mth_nm),
			case_method(case_mth)
		{}

		void operator()()
		{
			case_method();
		}
	};

	class check_assertion_indicator : public std::exception
	{
		public:
			check_assertion_indicator() : std::exception() {}
	};


	template <bool ExpectedResult>
	struct result_checker
	{
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const bool& predicate)
		{
			return predicate == ExpectedResult;
		}
	};


	struct equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs == rhs;
		}
	};


	struct not_equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs != rhs;
		}
	};


	struct greater_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs > rhs;
		}
	};


	struct less_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs < rhs;
		}
	};


	struct greater_equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs >= rhs;
		}
	};


	struct less_equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return lhs <= rhs;
		}
	};


	struct close_checker
	{
		template <typename T1,typename T2,typename T3>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs,const T3& tol)
		{
			return std::fabs((lhs) - (rhs)) < tol;
		}
	};


	struct string_equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return !::std::strcmp(lhs,rhs);
		}
	};


	struct string_not_equals_checker
	{
		template <typename T1,typename T2>
		static CYNODELIC_TESTER_ALWAYS_INLINE bool call(const T1& lhs,const T2& rhs)
		{
			return !(!::std::strcmp(lhs,rhs));
		}
	};


#ifdef CYNODELIC_TESTER_OS_WINDOWS
	struct hconsole
	{
		static HANDLE& get()
		{
			static HANDLE instance = GetStdHandle(STD_OUTPUT_HANDLE);

			return instance;
		}
	};
#endif
} // end of "detail" namespace

#endif // DOXYGEN_SHOULD_SKIP_THIS



/**
 * @brief Helper for coloring of console outputs
 */
class stdout_color
{
	private:
		CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(red_stdout_t,FOREGROUND_RED | FOREGROUND_INTENSITY,"\033[1;31m");
		CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(green_stdout_t,FOREGROUND_GREEN | FOREGROUND_INTENSITY,"\033[1;32m");
		CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(cyan_stdout_t,FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,"\033[1;36m");
		CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(magenta_stdout_t,FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,"\033[1;35m");
		CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER(normal_stdout_t,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,"\033[0m");
	public:
		/**
		 * @brief Default constructor
		 */
		stdout_color()
		{
			red_stdout_t::enable(true);
			green_stdout_t::enable(true);
			cyan_stdout_t::enable(true);
			magenta_stdout_t::enable(true);
			normal_stdout_t::enable(true);
		}


		/**
		 * @brief Enables console text coloring
		 *
		 * If `en` is `true`, the color modifiers will have effect, i.e., the text in
		 * console can be colored. 
		 */
		static void enable(const bool& en)
		{
			red_stdout_t::enable(en);
			green_stdout_t::enable(en);
			cyan_stdout_t::enable(en);
			magenta_stdout_t::enable(en);
			normal_stdout_t::enable(en);
		}


		/**
		 * @brief Red console output
		 *
		 * Turns red the text in console.
		 */
		static const red_stdout_t& red()
		{
			static red_stdout_t instance;

			return instance;
		}


		/**
		 * @brief Green console output
		 *
		 * Turns green the text in console.
		 */
		static const green_stdout_t& green()
		{
			static green_stdout_t instance;

			return instance;
		}


		/**
		 * @brief Cyan console output
		 *
		 * Turns cyan the text in console.
		 */
		static const cyan_stdout_t& cyan()
		{
			static cyan_stdout_t instance;

			return instance;
		}


		/**
		 * @brief Magenta console output
		 *
		 * Turns red the text in console.
		 */
		static const magenta_stdout_t& magenta()
		{
			static magenta_stdout_t instance;

			return instance;
		}


		/**
		 * @brief Normal console output
		 *
		 * Turns the text in console to its _default_ color.
		 */
		static const normal_stdout_t& normal()
		{
			static normal_stdout_t instance;

			return instance;
		}
};


#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace detail
{
	/**
	 * @brief Helper function for printing the status of a checking.
	 */
	template <check_status>
	void display_check_status(
		std::ostream& os,
		const bool& quiet,
		const char& show_fl,
		const char& show_tm,
		const bool& condv,
		const std::string& cond_str,
		const std::string& file_name,
		const std::size_t& line_num,
		const double& chk_duration
	)
	{
		if (!quiet)
		{
			if (!condv)
			{
				os << stdout_color::red() << "[FAILED] " << stdout_color::normal() << cond_str;
				
				if (show_fl == 'a' || show_fl == 'f')
				{
					os << " [" << file_name << ":" << line_num << "]";
				}
				
				if (show_tm == 'a' || show_tm == 'f')
				{
					os << " [time: " << chk_duration << " ms]";
				}
			}
			else
			{
				os << stdout_color::green() << "[ PASS ] " << stdout_color::normal() << cond_str;
				
				if (show_fl == 'a' || show_fl == 'p')
				{
					os << " [" << file_name << ":" << line_num << "]";
				}
				
				if (show_tm == 'a' || show_tm == 'p')
				{
					os << " [time: " << chk_duration << " ms]";
				}
			}
			
			os << '\n';
		}
	}


	/**
	 * @brief Helper function for printing the status of a checking.
	 */
	template <>
	void display_check_status<check_status::failed_warning>(
		std::ostream& os,
		const bool& quiet,
		const char& show_fl,
		const char& show_tm,
		const bool& condv,
		const std::string& cond_str,
		const std::string& file_name,
		const std::size_t& line_num,
		const double& chk_duration
	)
	{
		if (!quiet)
		{
			if (!condv)
			{
				os << stdout_color::magenta() << "[ WARN ] " << stdout_color::normal() << cond_str;
				
				if (show_fl == 'a' || show_fl == 'w')
				{
					os << " [" << file_name << ":" << line_num << "]";
				}
				
				if (show_tm == 'a' || show_tm == 'w')
				{
					os << " [time: " << chk_duration << " ms]";
				}
			}
			else
			{
				os << stdout_color::green() << "[ PASS ] " << stdout_color::normal() << cond_str;
				
				if (show_fl == 'a' || show_fl == 'p')
				{
					os << " [" << file_name << ":" << line_num << "]";
				}
				
				if (show_tm == 'a' || show_tm == 'p')
				{
					os << " [time: " << chk_duration << " ms]";
				}
			}
			
			os << '\n';
		}
	}

	/**
	 * @brief Helper function for printing the status of a checking.
	 */
	template <check_status>
	void display_error_status(
		std::ostream& os,
		const bool& quiet,
		const char& show_fl,
		const std::string& cond_str,
		const std::string& file_name,
		const std::size_t& line_num
	)
	{
		if (!quiet)
		{
			os << stdout_color::red() << "[FAILED] " << stdout_color::normal() << cond_str;
				
			if (show_fl == 'a' || show_fl == 'f')
			{
				os << " [" << file_name << ":" << line_num << "]";
			}
			
			os << '\n';
		}
	}


	/**
	 * @brief Helper function for printing the status of a checking.
	 */
	template <>
	void display_error_status<check_status::failed_warning>(
		std::ostream& os,
		const bool& quiet,
		const char& show_fl,
		const std::string& cond_str,
		const std::string& file_name,
		const std::size_t& line_num
	)
	{
		if (!quiet)
		{
			os << stdout_color::magenta() << "[ WARN ] " << stdout_color::normal() << cond_str;
				
			if (show_fl == 'a' || show_fl == 'w')
			{
				os << " [" << file_name << ":" << line_num << "]";
			}

			os << '\n';
		}
	}

	template <typename TestCase>
	struct basic_test_case_context
	{
		static bool quiet;
		static char show_fl;
		static char show_tm;
		static bool has_assertion_fail;

		basic_test_case_context() = default;
		
		static void set_output_parameters(const bool& quiet_,const char& show_fl_,const char& show_tm_)
		{
			quiet   = quiet_;
			show_fl = show_fl_;
			show_tm = show_tm_;
		}

		static std::vector<test_section_holder>& test_sections()
		{
			static std::vector<test_section_holder> instance;

			return instance;
		}

		static std::vector<test_check_result_holder>& tcase_check_results()
		{
			static std::vector<test_check_result_holder> instance;
			
			return instance;
		}

		static void add_section(const test_section_holder& mth)
		{
			test_sections().push_back(mth);
		}

		static std::string& current_section_name()
		{
			static std::string instance;

			return instance;
		}

		template <check_status FailStatus>
		static void add_check_result(
			const std::string&         fname,
			const std::string&         chk_str,
			const std::size_t&         line_n,
			const bool&                pred_res,
			const clock_duration_type& chk_dur
		)
		{
			display_check_status<FailStatus>(
				std::cout,
				quiet,
				show_fl,show_tm,
				pred_res,
				chk_str,
				fname,line_n,
				std::chrono::duration<double,std::milli>(chk_dur).count()
			);

			test_check_result_holder chk_res(
				fname,
				current_section_name(),
				chk_str,
				line_n,
				chk_dur,
				(pred_res ? check_status::passed : FailStatus)
			);
			
			tcase_check_results().push_back(chk_res);

			if (FailStatus == check_status::failed_assertion)
			{
				has_assertion_fail = !pred_res;
			}
		}

		template <check_status FailStatus>
		static void add_error(const test_check_result_holder& chk_res)
		{
			display_error_status<FailStatus>(
				std::cout,
				quiet,
				show_fl,
				chk_res.check_str,
				chk_res.file_name,
				chk_res.line_num
			);
			
			tcase_check_results().push_back(chk_res);

			if (FailStatus == check_status::failed_assertion)
			{
				std::cout << stdout_color::red() << "[------] " << stdout_color::normal() << "******** The current test case was aborted.\n";

				has_assertion_fail = true;
			}
		}
	};

	template <typename TestCase>
	bool basic_test_case_context<TestCase>::quiet;
		
	template <typename TestCase>
	char basic_test_case_context<TestCase>::show_fl;
		
	template <typename TestCase>
	char basic_test_case_context<TestCase>::show_tm;

	template <typename TestCase>
	bool basic_test_case_context<TestCase>::has_assertion_fail = false;


	/**
	 * @brief Holds the defined test cases
	 */
	struct test_cases
	{
		static std::vector<detail::test_case_holder>& get()
		{
			static std::vector<detail::test_case_holder> instance;

			return instance;
		}

		static void add_case(const detail::test_case_holder& tcase)
		{
			get().push_back(tcase);
		}
	};
} // end of "detail" namespace

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @brief Helper for messages
 */
template <typename TestCaseContext,check_status FailStatus>
class test_check_helper
{
	public:
		test_check_helper(
			std::ostream&              os,
			const std::string&         file_name,
			const std::string&         check_str,
			const std::size_t&         line_num,
			const bool&                pred_res,
			const clock_duration_type& chk_dur
		) :
			os_ref(os)
		{
			TestCaseContext::template add_check_result<FailStatus>(file_name,check_str,line_num,pred_res,chk_dur);

			chk_res = TestCaseContext::tcase_check_results().back();
		}

		~test_check_helper()
		{
			if (chk_res.chk_status != check_status::passed)
			{
				print_message(detail::as_tag<FailStatus>{});
			}
		}


		test_check_helper<TestCaseContext,FailStatus>& get_result(bool& out)
		{
			out = (chk_res.chk_status == check_status::passed);

			return *this;
		}


		template <typename T>
		test_check_helper<TestCaseContext,FailStatus>& operator<<(const T& input)
		{
			std::stringstream ss;
			ss << input;

			inputs.push_back(detail::input_holder(ss.str()));

			return *this;
		}


		test_check_helper<TestCaseContext,FailStatus>& operator<<(const newline_t&)
		{
			inputs.push_back(detail::input_holder(newline));

			return *this;
		}
	private:
		std::ostream&                     os_ref;
		std::vector<detail::input_holder> inputs;
		detail::test_check_result_holder  chk_res;


		void print_message(detail::as_tag<check_status::failed_warning>)
		{
			if (!TestCaseContext::quiet && inputs.size() != 0)
			{
				os_ref << stdout_color::magenta() << "[      ] " << stdout_color::normal();

				for (const detail::input_holder& ip : inputs)
				{
					switch (ip.get_flag())
					{
						case detail::input_holder::iph_flag::is_string:
							os_ref << ip.get_str();
							break;
						case detail::input_holder::iph_flag::is_newline:
							os_ref << '\n' << stdout_color::magenta() << "[      ] " << stdout_color::normal(); 
							break;
					}
				}
				os_ref << '\n';
			}
		}


		void print_message(detail::as_tag<check_status::failed_check>)
		{
			if (!TestCaseContext::quiet && inputs.size() != 0)
			{
				os_ref << stdout_color::red() << "[      ] " << stdout_color::normal();
				
				for (const detail::input_holder& ip : inputs)
				{
					switch (ip.get_flag())
					{
						case detail::input_holder::iph_flag::is_string:
							os_ref << ip.get_str();
							break;
						case detail::input_holder::iph_flag::is_newline:
							os_ref << '\n' << stdout_color::red() << "[      ] " << stdout_color::normal(); 
							break;
					}
				}
				os_ref << '\n';
			}
		}


		void print_message(detail::as_tag<check_status::failed_assertion>)
		{
			if (!TestCaseContext::quiet)
			{
				if (inputs.size() != 0 && inputs.size() != 0)
				{
					os_ref << stdout_color::red() << "[      ] " << stdout_color::normal();

					for (const detail::input_holder& ip : inputs)
					{
						switch (ip.get_flag())
						{
							case detail::input_holder::iph_flag::is_string:
								os_ref << ip.get_str();
								break;
							case detail::input_holder::iph_flag::is_newline:
								os_ref << '\n' << stdout_color::red() << "[      ] " << stdout_color::normal(); 
								break;
						}
					}
					os_ref << '\n';
				}
				os_ref << stdout_color::red() << "[------] " << stdout_color::normal() << "******** The current test case was aborted.\n";
			}
		}
};


/**
 * @brief Helper for in-test messages
 */
template <typename TestCaseContext>
class message_helper
{
	public:
		message_helper(std::ostream& os) :
			os_ref(os)
		{}


		~message_helper()
		{
			if (!TestCaseContext::quiet && inputs.size() != 0)
			{
				os_ref << stdout_color::cyan() << "[ MSSG ] " << stdout_color::normal();

				for (const detail::input_holder& ip : inputs)
				{
					if (ip.get_flag() == detail::input_holder::iph_flag::is_string)
					{
						os_ref << ip.get_str();
					}
					else if (ip.get_flag() == detail::input_holder::iph_flag::is_newline)
					{
						os_ref << '\n' << stdout_color::cyan() << "[      ] " << stdout_color::normal(); 
					}
				}
				os_ref << '\n';
			}
		}


		template <typename T>
		message_helper& operator<<(const T& input)
		{
			std::stringstream ss;
			ss << input;

			inputs.push_back(detail::input_holder(ss.str()));

			return *this;
		}


		message_helper& operator<<(const newline_t&)
		{
			inputs.push_back(detail::input_holder(newline));

			return *this;
		}
	private:
		std::ostream&                     os_ref;
		std::vector<detail::input_holder> inputs;
};


/**
 * @brief Helper for errors
 */
template <typename TestCaseContext,check_status FailStatus>
class error_helper
{
	public:
		error_helper(
			std::ostream& os,
			const std::string& file_name,
			const std::size_t& line_num
		) :
			os_ref(os),
			chk_res(
				detail::test_check_result_holder(
					file_name,
					TestCaseContext::current_section_name(),
					"(no description)",
					line_num,
					clock_duration_type(0),
					FailStatus
				)
			),
			has_stream_inputs(false)
		{}

		~error_helper()
		{
			if (chk_res.chk_status != check_status::passed)
			{
				if (has_stream_inputs && inputs.size() != 0)
				{
					std::stringstream ss;

					for (const detail::input_holder& ip : inputs)
					{
						if (ip.get_flag() == detail::input_holder::iph_flag::is_string)
						{
							ss << ip.get_str();
						}
						else if (ip.get_flag() == detail::input_holder::iph_flag::is_newline)
						{
							ss << '\n'; 
						}
					}

					chk_res.check_str = ss.str();
				}

				TestCaseContext::template add_error<FailStatus>(chk_res);
			}
		}


		error_helper<TestCaseContext,FailStatus>& get_failed_assertion_result(bool& out)
		{
			out = true;

			return *this;
		}


		template <typename T>
		error_helper<TestCaseContext,FailStatus>& operator<<(const T& input)
		{
			has_stream_inputs = true;

			std::stringstream ss;
			ss << input;

			inputs.push_back(detail::input_holder(ss.str()));

			return *this;
		}


		error_helper<TestCaseContext,FailStatus>& operator<<(const newline_t&)
		{
			has_stream_inputs = true;

			inputs.push_back(detail::input_holder(newline));

			return *this;
		}
	private:
		std::ostream&                     os_ref;
		detail::test_check_result_holder  chk_res;
		bool                              has_stream_inputs;
		std::vector<detail::input_holder> inputs;
};


/**
 * @brief Holds test cases
 */
template <typename TestCase>
struct basic_test_case
{
	static void initialize()
	{
		TestCase::test_case_context::has_assertion_fail = false;

		TestCase::test_case_context::current_section_name() = std::string{};

		detail::test_cases::add_case(detail::test_case_holder(TestCase::case_name,run));
	}

	static detail::test_case_result_holder run(const bool& quiet,const char& show_fl,const char& show_tm)
	{
		TestCase::test_case_context::set_output_parameters(quiet,show_fl,show_tm);
		
		std::size_t num_passed   = 0;
		std::size_t num_warnings = 0;
			
		clock_duration_type total_time(0);
		
		if (!quiet)
			std::cout << "[      ] Test case: " << TestCase::case_name << "\n";
		
		bool assertion_done = false;
		
		for (detail::test_section_holder test_sec : TestCase::test_case_context::test_sections())
		{
			if (!quiet)
				std::cout << "[      ] Section:   " << test_sec.section_name << "\n";
			
			try
			{
				test_sec();
			}
			catch (const detail::check_assertion_indicator&)
			{
				assertion_done = true;
				break;
			}
		}
		
		for (detail::test_check_result_holder tcrh : TestCase::test_case_context::tcase_check_results())
		{
			if (tcrh.chk_status == check_status::passed)
				num_passed++;
			else if  (tcrh.chk_status == check_status::failed_warning)
				num_warnings++;
			
			total_time += tcrh.test_time;
		}
		
		std::size_t num_checkings = TestCase::test_case_context::tcase_check_results().size();
		
		if (!quiet)
		{
			std::cout << "-------- " << num_passed << " out of " << (num_checkings - num_warnings) << " test checkings have been passed.\n";
			
			if (num_warnings == 1)
			{
				std::cout << "-------- 1 warning found.\n";
			}
			else if (num_warnings > 1)
			{
				std::cout << "-------- " << num_warnings << " warnings found.\n";
			}
			
			std::cout << "-------- Time: " << std::chrono::duration<double>(total_time).count() << " seconds\n";
			std::cout << "\n";
		}
		
		check_status status = (num_passed == (num_checkings - num_warnings)) ?
			check_status::passed :
			(
				assertion_done ?
				check_status::failed_assertion :
				check_status::failed_check
			);
		
		return detail::test_case_result_holder(
			TestCase::case_name,
			total_time,
			num_checkings,
			num_passed,
			num_checkings - num_passed,
			TestCase::test_case_context::tcase_check_results(),
			status
		);
	}
};


/**
 * @brief Holds test sections
 */
template <typename TestCase,typename TestSection>
struct basic_test_section
{
	using test_case_context = typename TestCase::test_case_context;


	static int& curr_stt_()
	{
		static int instance = 0;
		return instance;
	}

	static clock_duration_type& curr_dur_()
	{
		static clock_duration_type instance(0);
		return instance;
	}


	basic_test_section()
	{
		test_case_context::add_section(detail::test_section_holder(TestCase::case_name,TestSection::section_name,TestSection::run));
	}
};


/**
 * @brief Generates the help for the test program
 */
template <typename CharT,typename Traits>
void generate_help(std::basic_ostream<CharT,Traits>& os,char** argv)
{
	os << "Usage: " << argv[0] << " [arguments] [test cases]\n";
	os << "Arguments:\n";
	os << "    -h/--help:\n";
	os << "        This help.\n";
	os << "    -v/--version:\n";
	os << "        Shows the version of the unit testing framework used.\n";
	os << "    -i/--info:\n";
	os << "        Shows information abour this test program.\n";
	os << "    -l/--line [option]:\n";
	os << "        Shows the file and line of each test checking (default: a).\n";
	os << "        Options:\n";
	os << "            a/all:      For both failed and passed checkings.\n";
	os << "            w/warnings: For warnings.\n";
	os << "            f/failed:   For failed checkings.\n";
	os << "            p/passed:   For passed checkings.\n";
	os << "            n/none:     Shows nothing.\n";
	os << "    -nc/--no-color:\n";
	os << "        Disables output coloring.\n";
	os << "    -t/--time [option]:\n";
	os << "        Shows the elapsed time for each checking (default: a).\n";
	os << "        Options:\n";
	os << "            a/all:      For both failed and passed checkings.\n";
	os << "            w/warnings: For warnings.\n";
	os << "            f/failed:   For failed checkings.\n";
	os << "            p/passed:   For passed checkings.\n";
	os << "            n/none:     Shows nothing.\n";
	os << "Test cases:\n";

	if (detail::test_cases::get().empty())
	{
		os << "    [no test cases were defined]\n";
	}
	else
	{
		os << "    -rall/--run-all:\n";
		os << "        Runs all the test cases.\n";
		os << "    -rshuffled/--run-shuffled:\n";
		os << "        Runs all the test cases in random order.\n";
		for (detail::test_case_holder tch : detail::test_cases::get())
		{
			os << "    " << tch.short_flag << "/" << tch.long_flag << ":\n";
			os << "        " << "Runs the \"" << tch.case_name << "\" test case.\n"; 
		}
		os << "\n";
		os << "For running some specific test cases, more than one flag for each individual test case can be set. Also,\n";
		os << "a single flag can be set several times.\n";
		os << "If wrong arguments are set between some of these flags, they will be ignored.\n";
	}
}


/**
 * @brief Runs the tests
 *
 * The function that will run the tests.
 *
 * @param argc The `argc` of the `main` function.
 * @param argv The `argv` of the `main` function.
 */
test_exit_status run_tests(int argc,char** argv)
{
	if (argc == 1 || (argc == 2 && (!std::strcmp(argv[1],"-h") || !std::strcmp(argv[1],"--help"))))
	{
		generate_help(std::cout,argv);

		return test_exit_status::exec_success;
	}

	if (argc == 2 && (!std::strcmp(argv[1],"-v") || !std::strcmp(argv[1],"--version")))
	{
		std::cout << "Version of cynodelic::tester used here: " << CYNODELIC_TESTER_VERSION << "\n";

		return test_exit_status::exec_success;
	}

	if (argc == 2 && (!std::strcmp(argv[1],"-i") || !std::strcmp(argv[1],"--info")))
	{
		std::cout << "Version of cynodelic::tester used here: " << CYNODELIC_TESTER_VERSION << "\n";
		std::cout << "Compilation date and time:              " << __DATE__ << ", " << __TIME__ << "\n";
		std::cout << "Number of test cases:                   " << detail::test_cases::get().size() << "\n";
		std::cout << "Test cases:\n";
		for (detail::test_case_holder tch : detail::test_cases::get())
		{
			std::cout << "    " << tch.case_name << "\n";
		}

		return test_exit_status::exec_success;
	}

	std::size_t num_cases = detail::test_cases::get().size();

	if (num_cases == 0)
	{
		std::cout << "No test cases were defined.\n";

		return test_exit_status::exec_failure;
	}

	std::size_t start_at     = 1;
	std::size_t arg_jump     = 1;
	bool        cases_called = false;

	char show_fl  = 'a';
	char show_tm  = 'a';
	bool quiet    = false;
	bool colorize = true;

	std::vector<detail::test_case_result_holder> passed_cases;
	std::vector<detail::test_case_result_holder> failed_cases;
	std::vector<detail::test_case_result_holder> aborted_cases;

	clock_duration_type total_time{};

	for (std::size_t i = start_at; i < static_cast<std::size_t>(argc); i += arg_jump)
	{
		if (!std::strcmp(argv[start_at],"-nc") || !std::strcmp(argv[start_at],"--no-color"))
		{
			colorize = false;

			arg_jump  = 1;
			start_at += arg_jump;
		}
		else if (!std::strcmp(argv[start_at],"-l") || !std::strcmp(argv[start_at],"--line"))
		{
			if (!std::strcmp(argv[start_at + 1],"a") || !std::strcmp(argv[start_at + 1],"all"))
			{
				show_fl = 'a';
			}
			else if (!std::strcmp(argv[start_at + 1],"w") || !std::strcmp(argv[start_at + 1],"warnings"))
			{
				show_fl = 'w';
			}
			else if (!std::strcmp(argv[start_at + 1],"p") || !std::strcmp(argv[start_at + 1],"passed"))
			{
				show_fl = 'p';
			}
			else if (!std::strcmp(argv[start_at + 1],"f") || !std::strcmp(argv[start_at + 1],"failed"))
			{
				show_fl = 'f';
			}
			else if (!std::strcmp(argv[start_at + 1],"n") || !std::strcmp(argv[start_at + 1],"none"))
			{
				show_fl = 'n';
			}
			else
			{
				generate_help(std::cout,argv);

				return test_exit_status::exec_failure;
			}

			arg_jump  = 2;
			start_at += arg_jump;
		}
		else if (!std::strcmp(argv[start_at],"-t") || !std::strcmp(argv[start_at],"--time"))
		{
			if (!std::strcmp(argv[start_at + 1],"a") || !std::strcmp(argv[start_at + 1],"all"))
			{
				show_tm = 'a';
			}
			else if (!std::strcmp(argv[start_at + 1],"w") || !std::strcmp(argv[start_at + 1],"warnings"))
			{
				show_tm = 'w';
			}
			else if (!std::strcmp(argv[start_at + 1],"p") || !std::strcmp(argv[start_at + 1],"passed"))
			{
				show_tm = 'p';
			}
			else if (!std::strcmp(argv[start_at + 1],"f") || !std::strcmp(argv[start_at + 1],"failed"))
			{
				show_tm = 'f';
			}
			else if (!std::strcmp(argv[start_at + 1],"n") || !std::strcmp(argv[start_at + 1],"none"))
			{
				show_tm = 'n';
			}
			else
			{
				generate_help(std::cout,argv);

				return test_exit_status::exec_failure;
			}

			arg_jump  = 2;
			start_at += arg_jump;
		}
		else if (!std::strcmp(argv[start_at],"-q") || !std::strcmp(argv[start_at],"--quiet"))
		{
			quiet = true;

			arg_jump  = 1;
			start_at += arg_jump;
		}
	}

	stdout_color::enable(colorize);
	std::cout << stdout_color::normal();

	if (start_at == static_cast<std::size_t>(argc))
	{
		std::cout
			<< "No cases were called.\n"
			<< "Run \"" << argv[0] << " --help\" for showing the avaliable test cases and their respective flags.\n";

		return test_exit_status::exec_failure;
	}

	if (!std::strcmp(argv[start_at],"-rall") || !std::strcmp(argv[start_at],"--run-all"))
	{
		cases_called = true;

		for (detail::test_case_holder tch : detail::test_cases::get())
		{
			detail::test_case_result_holder tcase_res = tch(quiet,show_fl,show_tm);

			total_time += tcase_res.test_time;

			if (tcase_res.case_status == check_status::passed)
			{
				passed_cases.push_back(tcase_res);
			}
			else if (tcase_res.case_status == check_status::failed_check)
			{
				failed_cases.push_back(tcase_res);
			}
			else if (tcase_res.case_status == check_status::failed_assertion)
			{
				aborted_cases.push_back(tcase_res);
			}
		}
	}
	else if (!std::strcmp(argv[start_at],"-rshuffled") || !std::strcmp(argv[start_at],"--run-shuffled"))
	{
		cases_called = true;

		random_engine rnd(clock_type::now().time_since_epoch().count());

		std::vector<detail::test_case_holder> shuffled = detail::test_cases::get();

		std::shuffle(shuffled.begin(),shuffled.end(),rnd);


		for (detail::test_case_holder tch : shuffled)
		{
			detail::test_case_result_holder tcase_res = tch(quiet,show_fl,show_tm);

			total_time += tcase_res.test_time;

			if (tcase_res.case_status == check_status::passed)
			{
				passed_cases.push_back(tcase_res);
			}
			else if (tcase_res.case_status == check_status::failed_check)
			{
				failed_cases.push_back(tcase_res);
			}
			else if (tcase_res.case_status == check_status::failed_assertion)
			{
				aborted_cases.push_back(tcase_res);
			}
		}
	}
	else
	{
		for (std::size_t i = start_at; i < static_cast<std::size_t>(argc); i++)
		{
			std::string carg(argv[i]);

			for (detail::test_case_holder tch : detail::test_cases::get())
			{
				bool lnf_check = tch.long_flag == carg;
				bool shf_check = tch.short_flag == carg;

				if ((!lnf_check && shf_check) || (lnf_check && !shf_check))
				{
					cases_called = true;

					detail::test_case_result_holder tcase_res = tch(quiet,show_fl,show_tm);

					total_time += tcase_res.test_time;

					if (tcase_res.case_status == check_status::passed)
					{
						passed_cases.push_back(tcase_res);
					}
					else if (tcase_res.case_status == check_status::failed_check)
					{
						failed_cases.push_back(tcase_res);
					}
					else if (tcase_res.case_status == check_status::failed_assertion)
					{
						aborted_cases.push_back(tcase_res);
					}
				}
			}
		}
	}

	if (cases_called)
	{
		std::size_t failed_cnt  = failed_cases.size();
		std::size_t aborted_cnt = aborted_cases.size();

		double total_time_dbl = std::chrono::duration<double>(total_time).count();

		if (failed_cnt > 0 || aborted_cnt > 0)
		{
			if (failed_cnt > 0)
			{
				if (failed_cnt == 1)
					std::cout << "1 failure has been detected:\n";
				else
					std::cout << failed_cnt << " failures have been detected:\n";
				
				for (detail::test_case_result_holder tch : failed_cases)
				{
					std::vector<detail::test_check_result_holder> check_results = tch.tcase_check_results;

					std::cout << "    " << tch.case_name << ", on:\n";

					for (detail::test_check_result_holder tcr : check_results)
					{
						if (tcr.chk_status == check_status::failed_check)
						{
							std::cout << "        " << tcr.section_name << ": " << tcr.check_str << " [" << tcr.file_name << ":" << tcr.line_num << "]\n";
						}
					}
				}
			}

			if (aborted_cnt > 0)
			{
				if (aborted_cnt == 1)
					std::cout << "1 fatal failure has been detected:\n";
				else
					std::cout << aborted_cnt << " fatal failures have been detected:\n";
				
				for (detail::test_case_result_holder tch : aborted_cases)
				{
					std::vector<detail::test_check_result_holder> check_results = tch.tcase_check_results;

					std::cout << "    " << tch.case_name << ", on:\n";

					for (detail::test_check_result_holder tcr : check_results)
					{
						if (tcr.chk_status == check_status::failed_check)
						{
							std::cout << "         " << tcr.section_name << ": " << tcr.check_str << " [" << tcr.file_name << ":" << tcr.line_num << "]\n";
						}
						else if (tcr.chk_status == check_status::failed_assertion)
						{
							std::cout << "        *" << tcr.section_name << ": " << tcr.check_str << " [" << tcr.file_name << ":" << tcr.line_num << "]\n";
						}
					}
				}
			}

			std::cout << "All other tests passed successfully.\n";
			std::cout << "Time: " << total_time_dbl << " seconds.\n";

			return test_exit_status::test_failure;
		}
		else
		{
			std::cout << "All test cases passed successfully.\n";
			std::cout << "Time: " << total_time_dbl << " seconds.\n";

			return test_exit_status::test_success;
		}
	}

	generate_help(std::cout,argv);

	return test_exit_status::exec_failure;
}


}} // end of "cynodelic::tester" namespace



// ********** Macros **********


/**
 * @brief Creates a test case
 *
 * Creates an empty test case, in which test methods can be added.
 *
 * @param casename The name of the test case.
 */
#define CYNODELIC_TESTER_TEST_CASE(casename) \
struct test_case_##casename : ::cynodelic::tester::basic_test_case<test_case_##casename> \
{ \
	struct test_case_context : ::cynodelic::tester::detail::basic_test_case_context<test_case_##casename> \
	{}; \
	\
	static constexpr const char *case_name = #casename; \
	\
	test_case_##casename() \
	{ \
		::cynodelic::tester::basic_test_case<test_case_##casename>::initialize(); \
	} \
} test_case_##casename##_instance


/**
 * @brief Creates a section for a test case
 *
 * Adds a new _section_ to a test case.
 *
 * @param casename    The name of the test case.
 * @param sectionname The name of the section.
 */
#define CYNODELIC_TESTER_SECTION(casename,sectionname) \
struct test_section_##casename##_##sectionname : ::cynodelic::tester::basic_test_section<test_case_##casename,test_section_##casename##_##sectionname> \
{ \
	using test_case_context = typename test_case_##casename::test_case_context; \
	\
	static constexpr const char *section_name = #sectionname; \
	\
	test_section_##casename##_##sectionname() : ::cynodelic::tester::basic_test_section<test_case_##casename,test_section_##casename##_##sectionname>() {}; \
	\
	static void run(); \
} test_section_##casename##_##sectionname##_instance; \
void test_section_##casename##_##sectionname::run()


/**
 * @brief Creates a test case with a single section
 *
 * Creates a test case with a single section (which is named `main`).
 *
 * @param casename The name of the test case.
 */
#define CYNODELIC_TESTER_TEST_CASE_SINGLE_SECTION(casename) \
CYNODELIC_TESTER_TEST_CASE(casename); \
CYNODELIC_TESTER_SECTION(casename,main)



// ********** Helper for check macros **********


#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**
 * @brief Helper for `CYNODELIC_TESTER_{WARN,CHECK,ASSERT}_*` macros
 */
#define CYNODELIC_TESTER_DETAIL_CHECK_IMPL(predicate_,predicate_str_,chk_fail_status_,...) \
if (test_case_context::has_assertion_fail) \
{ \
	throw ::cynodelic::tester::detail::check_assertion_indicator{}; \
} \
do \
{ \
	test_case_context::current_section_name() = section_name; \
	::cynodelic::tester::clock_time_point tpoint_a = ::cynodelic::tester::clock_type::now(); \
	bool pred_result = predicate_::call(__VA_ARGS__); \
	::cynodelic::tester::clock_time_point tpoint_b = ::cynodelic::tester::clock_type::now(); \
	curr_stt_() = pred_result ? 1 : 0; \
	curr_dur_() = tpoint_b - tpoint_a; \
} while (false); \
::cynodelic::tester::test_check_helper<test_case_context,chk_fail_status_>(std::cout,__FILE__,predicate_str_,__LINE__,(curr_stt_() == 1),curr_dur_())


/**
 * @brief Helper for `CYNODELIC_TESTER_{WARNING,ERROR,FAILURE}`
 */
#define CYNODELIC_TESTER_DETAIL_ERROR_IMPL(fail_status_) \
if (test_case_context::has_assertion_fail) \
{ \
	throw ::cynodelic::tester::detail::check_assertion_indicator{}; \
} \
do \
{ \
	test_case_context::current_section_name() = section_name; \
} while (false); \
::cynodelic::tester::error_helper<test_case_context,fail_status_>(std::cout,__FILE__,__LINE__)


#endif // DOXYGEN_SHOULD_SKIP_THIS



//  ********** Error/message macros **********


/**
 * @brief Message printer
 *
 * Prints messages, which are added with the `<<` operator. New lines can be
 * added using the @ref newline modifier.
 */
#define CYNODELIC_TESTER_MESSAGE \
if (test_case_context::has_assertion_fail) \
{ \
	throw ::cynodelic::tester::detail::check_assertion_indicator{}; \
} \
::cynodelic::tester::message_helper<test_case_context>(std::cout)


/**
 * @brief Emits a warning
 *
 * Works in a similar way to to `CYNODELIC_TESTER_WARN_TRUE(false)`. A custom
 * description can be added by using the `<<` (stream) operator, otherwise, it
 * will be `(no description)`.
 */
#define CYNODELIC_TESTER_WARNING() CYNODELIC_TESTER_DETAIL_ERROR_IMPL(::cynodelic::tester::check_status::failed_warning)


/**
 * @brief Emits an error
 *
 * Works in a similar way to to `CYNODELIC_TESTER_CHECK_TRUE(false)`. A custom
 * description can be added by using the `<<` (stream) operator, otherwise, it
 * will be `(no description)`.
 */
#define CYNODELIC_TESTER_ERROR() CYNODELIC_TESTER_DETAIL_ERROR_IMPL(::cynodelic::tester::check_status::failed_check)


/**
 * @brief Emits a fatal error
 *
 * Works in a similar way to to `CYNODELIC_TESTER_ASSERT_TRUE(false)`. A custom
 * description can be added by using the `<<` (stream) operator, otherwise, it
 * will be `(no description)`.
 */
#define CYNODELIC_TESTER_FAILURE() CYNODELIC_TESTER_DETAIL_ERROR_IMPL(::cynodelic::tester::check_status::failed_assertion)



// ********** Check macros - check only **********


/**
 * @brief Checks the result of a condition
 *
 * Checks if the result of a given condition is `true`. A custom error message 
 * can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_CHECK_TRUE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<true>,#cond " [expected: true]",::cynodelic::tester::check_status::failed_check,(cond))


/**
 * @brief Checks the result of a condition
 *
 * Checks if the result of a given condition is `false`. A custom error message 
 * can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_CHECK_FALSE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<false>,#cond " [expected: false]",::cynodelic::tester::check_status::failed_check,(cond))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs == rhs)`
 */
#define CYNODELIC_TESTER_CHECK_EQUALS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs != rhs)`
 */
#define CYNODELIC_TESTER_CHECK_NOT_EQUALS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs > rhs)`
 */
#define CYNODELIC_TESTER_CHECK_GREATER(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_checker,#lhs " > " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs < rhs)`
 */
#define CYNODELIC_TESTER_CHECK_LESS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_checker,#lhs " < " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs >= rhs)`
 */
#define CYNODELIC_TESTER_CHECK_GEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_equals_checker,#lhs " >= " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_CHECK_TRUE(lhs <= rhs)`
 */
#define CYNODELIC_TESTER_CHECK_LEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_equals_checker,#lhs " <= " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Checks the near-equality of two nummbers
 *
 * Checks if the near-equality between two floating-point numbers is
 * accomplished, with a given tolerance (the minimum difference
 * between the two values to compare). A custom error message can be set by
 * using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 * @param tol The tolerance.
 */
#define CYNODELIC_TESTER_CHECK_CLOSE(lhs,rhs,tol) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::close_checker,#lhs " ~= " #rhs " [tolerance: " #tol "]",::cynodelic::tester::check_status::failed_check,(lhs),(rhs),(tol))


/**
 * @brief Checks the equality of two strings
 *
 * Checks if two C-style strings are equal, i.e, each character of them
 * matches. A custom error message can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_CHECK_STRING_EQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))


/**
 * @brief Checks the inequality of two strings
 *
 * Checks if two C-style strings are not equal, i.e, each character of them
 * does not match. A custom error message can be set by using the `<<`
 * operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_CHECK_STRING_NEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_check,(lhs),(rhs))



// ********** Check macros - warning **********


/**
 * @brief Checks the result of a condition
 *
 * Checks if the result of a given condition is `true`, without altering the
 * results of the tests. A custom error message  can be set by using the `<<`
 * operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_WARN_TRUE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<true>,#cond " [expected: true]",::cynodelic::tester::check_status::failed_warning,(cond))


/**
 * @brief Checks the result of a condition
 *
 * Checks if the result of a given condition is `false`, without altering the
 * results of the tests. A custom error message  can be set by using the `<<`
 * operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_WARN_FALSE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<false>,#cond " [expected: false]",::cynodelic::tester::check_status::failed_warning,(cond))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs == rhs)`
 */
#define CYNODELIC_TESTER_WARN_EQUALS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs != rhs)`
 */
#define CYNODELIC_TESTER_WARN_NOT_EQUALS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs > rhs)`
 */
#define CYNODELIC_TESTER_WARN_GREATER(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_checker,#lhs " > " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs < rhs)`
 */
#define CYNODELIC_TESTER_WARN_LESS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_checker,#lhs " < " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs >= rhs)`
 */
#define CYNODELIC_TESTER_WARN_GEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_equals_checker,#lhs " >= " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_WARN_TRUE(lhs <= rhs)`
 */
#define CYNODELIC_TESTER_WARN_LEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_equals_checker,#lhs " <= " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Checks the near-equality of two nummbers
 *
 * Checks if the near-equality between two floating-point numbers is
 * accomplished, with a given tolerance (the minimum difference
 * between the two values to compare), without altering the test's results. A
 * custom error message can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 * @param tol The tolerance.
 */
#define CYNODELIC_TESTER_WARN_CLOSE(lhs,rhs,tol) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::close_checker,#lhs " ~= " #rhs " [tolerance: " #tol "]",::cynodelic::tester::check_status::failed_warning,(lhs),(rhs),(tol))


/**
 * @brief Checks the equality of two strings
 *
 * Checks if two C-style strings are equal, without altering the test's
 * results. A custom error message can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_WARN_STRING_EQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))


/**
 * @brief Checks the inequality of two strings
 *
 * Checks if two C-style strings are not equal, without altering the results of
 * the test. A custom error message can be set by using the `<<` operator.
 * The result can be obtained as a `bool` by calling the `.get_result(out)`
 * method, that will modify the given `out` variable, providing the result.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_WARN_STRING_NEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_warning,(lhs),(rhs))



// ********** Check macros - with assertion **********


/**
 * @brief Checks the result of a condition 
 *
 * Checks if the result of a given condition is `true`, otherwise, the test
 * case will stop running. A custom error message  can be set by using the `<<`
 * operator.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_ASSERT_TRUE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<true>,#cond " [expected: true]",::cynodelic::tester::check_status::failed_assertion,(cond))


/**
 * @brief Checks the result of a condition 
 *
 * Checks if the result of a given condition is `false`, otherwise, the test
 * case will stop running. A custom error message  can be set by using the `<<`
 * operator.
 *
 * @param cond The condition.
 */
#define CYNODELIC_TESTER_ASSERT_FALSE(cond) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::result_checker<false>,#cond " [expected: false]",::cynodelic::tester::check_status::failed_assertion,(cond))


/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs == rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_EQUALS(lhs,rhs)  CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs != rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_NOT_EQUALS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs > rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_GREATER(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_checker,#lhs " > " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs < rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_LESS(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_checker,#lhs " < " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs >= rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_GEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::greater_equals_checker,#lhs " >= " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Equivalent to `CYNODELIC_TESTER_ASSERT_TRUE(lhs <= rhs)`
 */
#define CYNODELIC_TESTER_ASSERT_LEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::less_equals_checker,#lhs " <= " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))



/**
 * @brief Checks the near-equality of two nummbers
 *
 * Checks if the near-equality between two floating-point numbers is
 * accomplished, with a given tolerance (the minimum difference
 * between the two values to compare), otherwise, the current test case will
 * stop running. A custom error message can be set by using the `<<` operator.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 * @param tol The tolerance.
 */
#define CYNODELIC_TESTER_ASSERT_CLOSE(lhs,rhs,tol) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::close_checker,#lhs " ~= " #rhs " [tolerance: " #tol "]",::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs),(tol))


/**
 * @brief Checks the equality of two strings
 *
 * Checks if two C-style strings are equal, otherwise, the test case will stop
 * running. A custom error message can be set by using the `<<` operator.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_ASSERT_STRING_EQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_equals_checker,#lhs " == " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))


/**
 * @brief Checks the inequality of two strings
 *
 * Checks if two C-style strings are not equal, otherwise, the test case will
 * stop running. A custom error message can be set by using the `<<` operator.
 *
 * @param lhs The first element to compare.
 * @param rhs The second element to compare.
 */
#define CYNODELIC_TESTER_ASSERT_STRING_NEQ(lhs,rhs) CYNODELIC_TESTER_DETAIL_CHECK_IMPL(::cynodelic::tester::detail::string_not_equals_checker,#lhs " != " #rhs,::cynodelic::tester::check_status::failed_assertion,(lhs),(rhs))
 


// ********** Main function **********


#ifndef CYNODELIC_TESTER_DISABLE_AUTO_MAIN

/**
 * @brief Main function
 *
 * A predefined `main` function, which can be disabled by defining the
 * `CYNODELIC_TESTER_DISABLE_AUTO_MAIN` macro before including this header.
 */
int main(int argc,char** argv)
{
	::cynodelic::tester::test_exit_status result = ::cynodelic::tester::run_tests(argc,argv);
	
	switch (result)
	{
		case ::cynodelic::tester::test_exit_status::exec_failure:
		case ::cynodelic::tester::test_exit_status::test_failure:
			return EXIT_FAILURE;
		case ::cynodelic::tester::test_exit_status::exec_success:
		case ::cynodelic::tester::test_exit_status::test_success:
			return EXIT_SUCCESS;
	}
}

#endif // CYNODELIC_TESTER_DISABLE_AUTO_MAIN


#ifdef CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER
#	undef CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER
#endif // CYNODELIC_TESTER_DETAIL_DEFINE_STDOUT_COLOR_MODIFIER


#endif // CYNODELIC_TESTER_HPP
