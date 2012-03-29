/*
   Copyright 2009 Brain Research Institute, Melbourne, Australia

   Written by David Raffelt, 15/06/11.

   This file is part of MRtrix.

   MRtrix is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   MRtrix is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with MRtrix.  If not, see <http://www.gnu.org/licenses/>.

 */

#ifndef __filter_base_h__
#define __filter_base_h__

#include <cassert>
#include <vector>
#include "ptr.h"
#include "math/matrix.h"
#include "image/header.h"

namespace MR
{
  namespace Filter
  {

    //! \addtogroup Filters
    // @{

    /*! A base class for all image input-output filters.
     * This class is designed to provide a consistent interface for
     * image-to-image filters that perform operations on data defined
     * using the GenericDataSet interface. This allows all derived filters
     * to work with any DataSet type.
     *
     * Typical usage of a filter:
     * \code
     *
     * Image::Header input_header (argument[0]);
     * Image::Voxel<float> input_voxel (input_header);

     * Image::Header mask_header (input_header);
     * // Set the desired output data type
     * mask_header.set_datatype(DataType::Int8);
     *
     * Filter::MyFilterClass<Image::Voxel<float>, Image::Voxel<int> > my_filter(input_voxel);
     *
     * // Let the Filter define the output dimensions, voxel size, stride and transform
     * mask_header.set_params(my_filter.get_output_params();
     * mask_header.create(argument[1]);
     *
     * Image::Voxel<int> mask_voxel (mask_header);
     * my_filter.execute(input_voxel, mask_voxel);
     *
     * \endcode
     */
    class Base : public ConstInfo
    {
      public:

        template <class InputSet> 
          Base (const InputSet& D) : 
            ConstInfo (D) { }

        virtual ~Base () { }

        template <class InputSet, class OutputSet> 
          void operator() (const InputSet& input, OutputSet& output) { 
          assert (0);
        }
    };





    Image::Voxel<> input;
    MyFilter filter (input);

    Image::Scratch<float> output (filter);
    filter (input, output);

    //! @}
  }
}

#endif

