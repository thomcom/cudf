/*
 * Copyright (c) 2020, NVIDIA CORPORATION.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cudf/strings/strings_column_view.hpp>
#include <cudf/column/column.hpp>

namespace cudf
{
namespace strings
{
/**
 * @brief Inserts new-line characters (ASCII 0x0A) into each string in place of spaces.  
 *
 * Returns a column of strings where, for each string row in the input, 
 * words separated by spaces will become separated by newline characters.
 * Attempts to make each line less than or equal to width characters. 
 * If a string or characters is longer than width, 
 * the line is split on the next closest space character. 
 *
 * Any null string entries return corresponding null output column entries.
 *
 * Example:
 * ```
 * width = 5
 * input_string_tbl = ["tesT1 test2", "more longtest short1", " other test "];
 *
 * wrapped_string_tbl = ["test1\ntest2", "more\nlongt\nest\nshort1", "other\ntest"]
 * ```
 *
 * @param[in] strings String column.
 * @param[in] width the maximum width of a line. 
 * @param[in] mr Resource for allocating device memory.
 * @return Column of wrapped strings.
 */
std::unique_ptr<column> wrap( strings_column_view const& strings,
                              size_type width,
                              rmm::mr::device_memory_resource* mr = rmm::mr::get_default_resource());
  
}//namespace strings
}//namespace cudf
