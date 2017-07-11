/**
	\brief CPU implementation of the non-cartesian FFT

	Comparisions were made to the gridkb function provided in the 
	Stanford Medical Image Reconstruction course lecture notes and 
	the Cuda version of the NFFT (cuNFFT)

	Uses the Kaiser Bessel for convolution
*/

#pragma once 

#include "hoNDArray.h"
#include "vector_td.h"
#include "complext.h"

#include <boost/shared_ptr.hpp>

#include "cpunfft_export.h"

namespace Gadgetron{
	
	/**
		NFFT class declaration
		----------------------

		Real: desired precision : float or double only 
		D: dimensionality: 1D, 2D, and 3D supported
	*/

	template<class Real, unsigned int D>
	class EXPORTCPUNFFT hoNFFT_plan{
	
		/**
			Main interface
		*/
		
		public:
			
			/**
				Default constructor
			*/
			
			hoNFFT_plan();

			/**
				Constructor defining the required NFFT parameters

				/param n: the non-oversampled matrix size to use for NFFT
				/param osf: the oversampling factor
				/param wg: the width of the oversampled kernel
			*/

			hoNFFT_plan(
				typename uint64d<D>::Type n,
				Real osf,
				Real wg
			);
			
			/** 
				Destructor
			*/

			~hoNFFT_plan();

			/**
				Enum to specify the preprocessing mode.
			*/

			enum NFFT_prep_mode{
				NFFT_PREP_C2NC, /** preprocess for carteisan to non cartesian */
				NFFT_PREP_NC2C, /** preprocess for non cartesian to cartesian */
				NFFT_PREP_ALL /** preprocess for both directions */
			};

			/** 
				Perform NFFT preprocessing for a given trajectory

				\param k: the NFFT non cartesian trajectory
					performs normalization if not between [-0.5, 0.5]
				\param mode: enum specifying the preprocessing mode
			*/

			void preprocess(
				hoNDArray<typename real1d<Real, D>::Type> k,
				NFFT_prep_mode mode
			);

			/**
				Enum defining the desired NFFT operation
			*/

			enum NFFT_comp_mode{
				NFFT_FORWARDS_C2NC, /** forwards cartesian to non */
				NFFT_BACKWARDS_NC2C, /** forwards non too cartesian */
				NFFT_BACKWARDS_C2NC, /** backwards cartesian to non */
				NFFT_FORWARDS_NC2C /** forwards non to cartesian */
			};

			/**
				Execute the NFFT

				\param d: the input data array
				\param m: the output matrix
				\param w: optional density compensation if not iterative 
					provide a 0x0 if non density compensation
				\param mode: enum specifyiing the mode of operation
			*/

			void compute(
				hoNDArray<complext<Real>> d,
				hoNDArray<complext<Rea>>> &m,
				hoNDArray<complext<Real>> w,
				NFFT_comp_mode mode
			);

			/** NEED TO INCLUDE mult_MH_M function for interation */

		/**
			Utilities
		*/

		public:
			
			/**
				Enum specifying the direction of the NFFT convolution 
			*/

			enum NFFT_conv_mode{
				NFFT_CONV_C2NC, /** cartesian to non convolution */
				NFFT_CONV_NC2C /** non to cartesian convolution */
			};

			/** 
				Perform standalone convolution
				
				\param d: input array
				\param m: output array
				\param mode: enum specifying the mode of the convolution
			*/

			void convolve(
				hoNDArray<complext<Real>> d,
				hoNDArray<complext<Real>> &m,
				NFFT_conv_mode mode
			);

			/** 
				enum specifying the direction of the NFFT fft
			*/

			enum NFFT_fft_mode{
				NFFT_FORWARDS,
				NFFT_BACKWARDS
			};

			/**
				Cartesian fft. Making use of the hoNDFFT class.

				\param d: input and output for he fft 
				\param mode: enum specifying the mode of the fft 
			*/

			void fft(
				hoNDArray<complext<Real>> d,
				NFFT_fft_mode mode
			);

			/**
				NFFT deapodization

				\param d: input and output image to be deapodized 
				\param fourierDomain: has data been ffted
			*/

			void deapodize(
				hoNDArray<complext<Real>> &d,
				bool fourierDomain = false
			);
			
		/**
			Private implementation methods
		*/

		private:
			
			/**
				Initialize variables and compute tables
			*/

			void initialize();

			/**
				Dedicated convolutions
			*/

			void convolve_NFFT_C2NC(
				hoNDArray<complext<Real>> d,
				hoNDArray<complext<Real>> &m
			);

			void convolve_NFFT_NC2C(
				hoNDArray<compelxt<Real>> d,
				hoNDArray<complext<Real>> &m
			);
		
		/** 
			Implementation variables
		*/

		private:
			
			typename uint64d<D>::Type n;
			Real kw, kosf, kwidth, beta;
			hoNDArray<Real> p, da, nx, ny, nz;

	}
}
