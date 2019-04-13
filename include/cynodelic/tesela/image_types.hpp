// Copyright (c) 2019 Álvaro Ceballos
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt

/**
 * @file image_types.hpp
 *
 * @brief Defines the `basic_image` container.
 */

#ifndef CYNODELIC_TESELA_IMAGE_TYPES_HPP
#define CYNODELIC_TESELA_IMAGE_TYPES_HPP


#include <cstdlib>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <utility>
#include <stdexcept>

#include <cynodelic/tesela/config.hpp>
#include <cynodelic/tesela/color_space.hpp>
#include <cynodelic/tesela/rgb_types.hpp>
#include <cynodelic/tesela/rgba_types.hpp>
#include <cynodelic/tesela/gray_types.hpp>
#include <cynodelic/tesela/ga_types.hpp>
#include <cynodelic/tesela/point.hpp>
#include <cynodelic/tesela/rectangle.hpp>


namespace cynodelic { namespace tesela {


/**
 * @ingroup types
 * @brief Image container
 *
 * A type that contains a image, that is, a two-dimensional array of pixels.
 *
 * @param PixelType A valid @link pixeltypes pixel type @endlink.
 */
template <typename PixelType>
class basic_image
{
	public:
		/**
		 * @brief Iterator type
		 *
		 * The random access iterator for @ref basic_image.
		 */
		template <typename PixelT_>
		class image_iterator
		{
			public:
				using self_type         = image_iterator<PixelT_>;
				using value_type        = PixelT_;
				using difference_type   = std::ptrdiff_t;
				using pointer           = PixelT_*;
				using reference         = PixelT_&;
				using iterator_category = std::random_access_iterator_tag;

				image_iterator() :
					data_ptr(nullptr)
				{}

				image_iterator(pointer addr) :
					data_ptr(addr)
				{}

				image_iterator(const self_type& other) :
					data_ptr(other.data_ptr)
				{}

				self_type& operator=(const self_type& other)
				{
					data_ptr = other.data_ptr;

					return *this;
				}

				self_type& operator++()
				{
					++data_ptr;
					return *this;
				}

				self_type& operator--()
				{
					--data_ptr;
					return *this;
				}

				self_type operator++(int)
				{
					data_ptr++;
					return *this;
				}

				self_type operator--(int)
				{
					data_ptr--;
					return *this;
				}

				self_type operator+(const difference_type& n) const
				{
					return self_type(data_ptr + n);
				}

				self_type& operator+=(const difference_type& n)
				{
					data_ptr += n;
					return *this;
				}

				self_type operator-(const difference_type& n) const
				{
					return self_type(data_ptr - n);
				}

				self_type& operator-=(const difference_type& n)
				{
					data_ptr -= n;
					return *this;
				}

				reference operator*() const
				{
					return *data_ptr;
				}

				pointer operator->() const
				{
					return data_ptr;
				}

				reference operator[](const difference_type& idx) const
				{
					return data_ptr[idx];
				}

				friend bool operator==(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr == rhs.data_ptr);
				}
				
				friend bool operator!=(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr != rhs.data_ptr);
				}
				
				friend bool operator>(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr > rhs.data_ptr);
				}
				
				friend bool operator<(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr < rhs.data_ptr);
				}
				
				friend bool operator>=(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr >= rhs.data_ptr);
				}
				
				friend bool operator<=(const self_type& lhs,const self_type& rhs)
				{
					return (lhs.data_ptr <= rhs.data_ptr);
				}

				friend difference_type operator+(const self_type& lhs,const self_type& rhs)
				{
					return lhs.data_ptr + rhs.data_ptr;
				}

				friend difference_type operator-(const self_type& lhs,const self_type& rhs)
				{
					return lhs.data_ptr - rhs.data_ptr;
				}
			private:
				pointer data_ptr;
		};

		using type                   = basic_image<PixelType>;                /**< @brief Reference to its own type */
		using value_type             = PixelType;                             /**< @brief Type of the values contained by `basic_image` */
		using size_type              = std::size_t;                           /**< @brief Size type */
		using difference_type        = std::ptrdiff_t;                        /**< @brief Pointer difference type */
		using iterator               = image_iterator<value_type>;            /**< @brief Iterator type */
		using const_iterator         = image_iterator<const value_type>;      /**< @brief Const-iterator type */
		using reverse_iterator       = std::reverse_iterator<iterator>;       /**< @brief Reverse iterator type */
		using const_reverse_iterator = std::reverse_iterator<const_iterator>; /**< @brief Reverse const-iterator type */

		/// @brief The type of the components of the pixel type.
		using component_type = typename PixelType::component_type;

		/// @brief The color space of the contained pixel type.
		static constexpr color_space contained_color_space = PixelType::pixel_color_space;

		
		/**
		 * @brief Default constructor
		 *
		 * Initializes a @ref basic_image as an empty image.
		 */
		basic_image() :
			img_writting_colspace(contained_color_space),
			width_(0), height_(0),
			size_(0),
			pixels(nullptr)
		{}

		
		/**
		 * @brief Initializes with width, height and color mode
		 * 
		 * Initializes the image with width, height and color mode.
		 *
		 * @param width     Image width.
		 * @param height    Image height.
		 * @param col_space Color space used to write the image.
		 */
		basic_image(const std::size_t& width,const std::size_t& height,color_space col_space = contained_color_space)
		{
			width_                = width;
			height_               = height;
			size_                 = width_*height_;
			img_writting_colspace = col_space;
			pixels                = new value_type[width*height];
		}

		
		/**
		 * @brief Initializes with rectangle and color mode
		 * 
		 * Initializes the image with a @ref rectangle and color mode. The `x` and `y`
		 * members of `rec` are ignored.
		 *
		 * @param rec       A @ref rectangle with width and height.
		 * @param col_space Color space used to write the image.
		 */
		basic_image(const rectangle& rec,color_space col_space = contained_color_space) :
			basic_image(rec.width,rec.height,col_space)
		{}

		
		/**
		 * @brief Copy constructor
		 *
		 * Initializes an image copying the contents of another one.
		 *
		 * @param other The instance.
		 */
		basic_image(const basic_image<PixelType>& other)
		{	
			// Allocate array
			pixels = new value_type[other.size_];
			
			// Copy content
			for (std::size_t i = 0; i < other.size_; i++)
				pixels[i] = other.pixels[i];
			
			width_                = other.width_;
			height_               = other.height_;
			size_                 = other.size_;
			img_writting_colspace = other.img_writting_colspace;
		}

		
		/**
		 * @brief Move constructor
		 *
		 * Initializes an image _moving_ the contents of another one.
		 *
		 * @param other The instance.
		 */
		basic_image(basic_image<PixelType>&& other) noexcept
		{
			pixels                = other.pixels;
			width_                = other.width_;
			height_               = other.height_;
			size_                 = other.size_;
			img_writting_colspace = other.img_writting_colspace;
			
			// "Reset" x
			other.pixels                = nullptr;
			other.size_                 = 0;
			other.width_                = 0;
			other.height_               = 0;
			other.img_writting_colspace = contained_color_space;
		}

		
		/// @brief Destructor.
		~basic_image() noexcept
		{
			delete [] pixels;
			pixels = nullptr;
		}

		
		/**
		 * @brief Copy assignment operator
		 *
		 * Replaces the content of an image with the contents of `other`.
		 */
		basic_image<PixelType>& operator=(const basic_image<PixelType>& other)
		{
			if (this == &other)
				return *this;

			// Deallocate array of pixels
			delete [] pixels;
			
			// Reallocate array
			pixels = new value_type[other.size_];
			
			// Copy content
			for (std::size_t i = 0; i < other.size_; i++)
				pixels[i] = other.pixels[i];
			
			width_                = other.width_;
			height_               = other.height_;
			size_                 = other.size_;
			img_writting_colspace = other.img_writting_colspace;
			
			return *this;
		}

		
		/**
		 * @brief Move assignment operator
		 *
		 * Replaces the content of an image, _moving_ the contents of `other`.
		 */
		basic_image<PixelType>& operator=(basic_image<PixelType>&& other) noexcept
		{
			if (this == &other)
				return *this;

			// Deallocate array of pixels
			delete [] pixels;
			
			pixels                = other.pixels;
			width_                = other.width_;
			height_               = other.height_;
			size_                 = other.size_;
			img_writting_colspace = other.img_writting_colspace;
			
			// "Reset" x
			other.pixels                = nullptr;
			other.size_                 = 0;
			other.width_                = 0;
			other.height_               = 0;
			other.img_writting_colspace = contained_color_space;
			
			return *this;
		}


		/**
		 * @brief Swaps the content
		 *
		 * Swaps (exchanges) the content of the image with those of another one.
		 *
		 * @param other The other instance.
		 */
		void swap(basic_image<PixelType>& other)
		{
			std::swap(width_,other.width_);
			std::swap(height_,other.height_);
			std::swap(size_,other.size_);
			std::swap(img_writting_colspace,other.img_writting_colspace);
			std::swap(pixels,other.pixels);
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its X-Y position.
		 *
		 * @param xpos X position.
		 * @param ypos Y position.
		 */
		value_type& operator()(const std::size_t& xpos,const std::size_t& ypos)
		{
			if (width_*ypos + xpos > size_)
				throw std::out_of_range("[cynodelic::tesela::basic_image<...>::operator()] Position outside the bounds of the image's internal array.");

			return pixels[width_*ypos + xpos];
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its X-Y position.
		 *
		 * @param xpos X position.
		 * @param ypos Y position.
		 */
		const value_type& operator()(const std::size_t& xpos,const std::size_t& ypos) const
		{
			if (width_*ypos + xpos > size_)
				throw std::out_of_range("[cynodelic::tesela::basic_image<...>::operator()] Position outside the bounds of the image's internal array.");

			return pixels[width_*ypos + xpos];
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its position in the underlying array.
		 *
		 * @param idx The position in the underlying array.
		 */
		value_type& operator[](const std::size_t& idx)
		{
			return pixels[idx];
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its position in the underlying array.
		 *
		 * @param pt The position in the underlying array.
		 */
		value_type& operator[](const point& pt)
		{
			return pixels[width_*pt.y + pt.x];
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its position in the underlying array.
		 *
		 * @param idx The position in the underlying array.
		 */
		const value_type& operator[](const std::size_t& idx) const
		{
			return pixels[idx];
		}

		
		/**
		 * @brief Accesses pixel from image
		 * 
		 * Accesses a pixel from the image, given its position in the underlying array.
		 *
		 * @param pt The position in the underlying array.
		 */
		const value_type& operator[](const point& pt) const
		{
			return pixels[width_*pt.y + pt.x];
		}


		/**
		 * @brief Sets the color space used to write the image
		 *
		 * Determines which color space will be the image written in.
		 *
		 * @param col_space The color space
		 */
		void write_with_color_space(const color_space& col_space)
		{
			img_writting_colspace = col_space;
		}


		/**
		 * @brief Gets the color space used to write the image
		 *
		 * Returns the color space that will be used to write the image.
		 */
		color_space get_color_space() const
		{
			return img_writting_colspace;
		}


		/**
		 * @brief Iterator to the beginning.
		 *
		 * Returns an iterator to the beginning of this container.
		 */
		iterator begin() noexcept
		{
			return iterator(pixels);
		}

		/**
		 * @brief Iterator to the beginning.
		 *
		 * Returns an iterator to the beginning of this container.
		 */
		const_iterator begin() const noexcept
		{
			return iterator(pixels);
		}

		/**
		 * @brief Iterator to the end.
		 *
		 * Returns an iterator to the end of this container.
		 */
		iterator end() noexcept
		{
			return iterator(pixels + size_);
		}

		/**
		 * @brief Iterator to the end.
		 *
		 * Returns an iterator to the end of this container.
		 */
		const_iterator end() const noexcept
		{
			return iterator(pixels + size_);
		}

		/**
		 * @brief Iterator to the beginning.
		 *
		 * Returns an iterator to the beginning of this container.
		 */
		const_iterator cbegin() const noexcept
		{
			return const_iterator(pixels);
		}

		/**
		 * @brief Iterator to the end.
		 *
		 * Returns an iterator to the end of this container.
		 */
		const_iterator cend() const noexcept
		{
			return const_iterator(pixels + size_);
		}

		/**
		 * @brief Reverse iterator to the beginning.
		 *
		 * Returns a reverse iterator to the beginning of this container.
		 */
		reverse_iterator rbegin() noexcept
		{
			return reverse_iterator(end());
		}

		/**
		 * @brief Reverse iterator to the end.
		 *
		 * Returns a reverse iterator to the end of this container.
		 */
		reverse_iterator rend() noexcept
		{
			return reverse_iterator(begin());
		}

		/**
		 * @brief Reverse iterator to the beginning.
		 *
		 * Returns a reverse iterator to the beginning of this container.
		 */
		const_reverse_iterator crbegin() const noexcept
		{
			return const_reverse_iterator(cend());
		}

		/**
		 * @brief Reverse iterator to the end.
		 *
		 * Returns a reverse iterator to the end of this container.
		 */
		const_reverse_iterator crend() const noexcept
		{
			return const_reverse_iterator(cbegin());
		}

		
		/**
		 * @brief Image width
		 * 
		 * Returns the width of the image.
		 */
		std::size_t width() const
		{
			return width_;
		}

		
		/**
		 * @brief Image height
		 * 
		 * Returns the height of the image.
		 */
		std::size_t height() const
		{
			return height_;
		}

		
		/**
		 * @brief Image size
		 * 
		 * Returns the size of the image, i.e., its ammount of pixels (width*height).
		 */
		std::size_t size() const
		{
			return size_;
		}


		/**
		 * @brief Checks if the container is empty
		 *
		 * Checks if the image container is empty, i.e., it has no pixels.
		 */
		bool empty() const
		{
			return (size_ == 0) || (*this->cbegin() == *this->cend());
		}

		
		/**
		 * @brief Width and height as a rectangle
		 * 
		 * Returns the width and height of an image, as a @ref rectangle.
		 */
		rectangle dimensions() const
		{
			return rectangle(width_,height_);
		}


		/**
		 * @brief Access to underlying array
		 *
		 * Returns a pointer to the container's underlying array.
		 */
		value_type* data() noexcept
		{
			return pixels;
		}


		/**
		 * @brief Access to underlying array
		 *
		 * Returns a pointer to the container's underlying array.
		 */
		const value_type* data() const noexcept
		{
			return pixels;
		}

		
		/**
		 * @brief Equality operator
		 *
		 * Checks if two images are equal, i.e., they have the same content.
		 */
		friend bool operator==(const basic_image<PixelType>& lhs,const basic_image<PixelType>& rhs)
		{
			if (!(lhs.width_ == rhs.width_ && lhs.height_ == rhs.height_))
				return false;
			
			for (std::size_t iy = 0; iy < lhs.height_; iy++)
			{
				for (std::size_t ix = 0; ix < lhs.width_; ix++)
				{
					if (lhs(ix,iy) != rhs(ix,iy))
						return false;
				}
			}
			
			return true;
		}

		
		/**
		 * @brief Inequality operator
		 *
		 * Checks if two images are not equal.
		 */
		friend bool operator!=(const basic_image<PixelType>& lhs,const basic_image<PixelType>& rhs)
		{
			return !(lhs == rhs);
		}
	private:
		color_space img_writting_colspace;
		std::size_t width_;
		std::size_t height_;
		std::size_t size_;
		value_type* pixels;
};

template <typename PixelType>
constexpr color_space basic_image<PixelType>::contained_color_space;


/**
 * @ingroup types
 * @brief Same as `basic_image<rgba_t>`.
 *
 * @deprecated Unnecessary alias. Use @ref rgba_image instead.
 */
using image = basic_image<rgba_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<nrgba_t>`.
 *
 * @deprecated Unnecessary alias. Use @ref nrgba_image instead.
 */
using norm_image = basic_image<nrgba_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<rgb_t>`.
 */
using rgb_image = basic_image<rgb_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<rgba_t>`.
 */
using rgba_image = basic_image<rgba_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<gray_t>`.
 */
using gray_image = basic_image<gray_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<ga_t>`.
 */
using ga_image = basic_image<ga_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<nrgb_t>`.
 */
using nrgb_image = basic_image<nrgb_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<nrgba_t>`.
 */
using nrgba_image = basic_image<nrgba_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<ngray_t>`.
 */
using ngray_image = basic_image<ngray_t>;


/**
 * @ingroup types
 * @brief Same as `basic_image<nga_t>`.
 */
using nga_image = basic_image<nga_t>;



}} // end of "cynodelic::tesela" namespace


#endif // CYNODELIC_TESELA_IMAGE_TYPES_HPP
