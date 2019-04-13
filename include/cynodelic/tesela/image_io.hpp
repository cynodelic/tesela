// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file image_io.hpp
 *
 * @brief Defines a helper for image input/output.
 */

#ifndef CYNODELIC_TESELA_IMAGE_IO_HPP
#define CYNODELIC_TESELA_IMAGE_IO_HPP


#include <cstdlib>
#include <string>
#include <regex>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/exceptions/io_error.hpp>
#include <cynodelic/tesela/image_types.hpp>
#include <cynodelic/tesela/type_casts.hpp>


namespace cynodelic { namespace tesela {


#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace detail
{
	/**
	 * @brief Helper for `image_io`
	 */
	template <typename Format,typename... Others>
	struct image_io_helper
	{
		/**
		 * @brief Reads an image file.
		 *
		 * Reads an image file, storing its content into an @ref image.
		 */
		template <typename PixelType>
		static inline void read(const std::string& file_name,basic_image<PixelType>& img)
		{
			std::regex fext_rgx(Format::file_extension_regex,Format::regex_syntax);

			if (std::regex_match(file_name,fext_rgx))
			{
				Format::read(file_name,img);
			}
			else
			{
				image_io_helper<Others...>::read(file_name,img);
			}
		}


		/**
		 * @brief Writes an image file.
		 *
		 * Writes the content of an @ref image to a image file.
		 */
		template <typename PixelType>
		static inline void write(const std::string& file_name,const basic_image<PixelType>& img)
		{
			std::regex fext_rgx(Format::file_extension_regex,Format::regex_syntax);

			if (std::regex_match(file_name,fext_rgx))
			{
				Format::write(file_name,img);
			}
			else
			{
				image_io_helper<Others...>::write(file_name,img);
			}
		}
	};


	/**
	 * @brief Helper for `image_io`
	 */
	template <typename Format>
	struct image_io_helper<Format>
	{
		/**
		 * @brief Reads an image file.
		 *
		 * Reads an image file, storing its content into an @ref image.
		 */
		template <typename PixelType>
		static inline void read(const std::string& file_name,basic_image<PixelType>& img)
		{
			std::regex fext_rgx(Format::file_extension_regex,Format::regex_syntax);

			if (std::regex_match(file_name,fext_rgx))
			{
				Format::read(file_name,img);
			}
			else
			{
				throw io_error(std::string("[cynodelic::tesela::image_io_helper<...>::read] No format used in this instance of \'image_io_helper\' could match for ") + file_name + std::string("."));
			}
		}


		/**
		 * @brief Writes an image file.
		 *
		 * Writes the content of an @ref image to a image file.
		 */
		template <typename PixelType>
		static inline void write(const std::string& file_name,const basic_image<PixelType>& img)
		{
			std::regex fext_rgx(Format::file_extension_regex,Format::regex_syntax);

			if (std::regex_match(file_name,fext_rgx))
			{
				Format::write(file_name,img);
			}
			else
			{
				throw io_error(std::string("[cynodelic::tesela::image_io_helper<...>::read] No format used in this instance of \'image_io_helper\' could match for ") + file_name + std::string("."));
			}
		}
	};
} // end of "detail" namespace

#endif // DOXYGEN_SHOULD_SKIP_THIS


/**
 * @ingroup imageio
 * @brief Image I/O helper
 *
 * A helper for reading and writing image files.
 *
 * @param ImgFormats... Valid image format types.
 */
template <typename... ImgFormats>
struct image_io
{
	/**
	 * @brief Reads an image file.
	 *
	 * Reads an image file, storing its content into an @ref image.
	 */
	template <typename PixelType>
	static void read(const std::string& file_name,basic_image<PixelType>& img)
	{
		detail::image_io_helper<ImgFormats...>::read(file_name,img);
	}


	/**
	 * @brief Writes an image file.
	 *
	 * Writes the content of an @ref image to a image file.
	 */
	template <typename PixelType>
	static void write(const std::string& file_name,const basic_image<PixelType>& img)
	{
		detail::image_io_helper<ImgFormats...>::write(file_name,img);
	}
};


}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_IMAGE_IO_HPP
