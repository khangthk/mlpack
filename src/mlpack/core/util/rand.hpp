/**
 * @file core/util/rand.hpp
 * @author Marcus Edel
 * @author Omar Shrit
 *
 * A simple `randX` wrapper that based on the data type and the function type,
 * e.g., randi, randn, randu forwards to coot::randX` or `arma::randX`. This
 * file is initially copied from ensmallen
 *
 * mlpack is free software; you may redistribute it and/or modify it under
 * the terms of the 3-clause BSD license.  You should have received a copy of
 * the 3-clause BSD license along with ensmallen.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_CORE_UTIL_RAND_HPP
#define MLPACK_CORE_UTIL_RAND_HPP

namespace mlpack {

#ifdef MLPACK_HAS_COOT

template<typename InputType>
InputType randi(const size_t rows,
                const size_t cols,
                const coot::distr_param& param
                const typename std::enable_if_t<
                    coot::is_coot_type<InputType>::value>* = 0)
{
  return coot::randi<InputType>(rows, cols,
      coot::distr_param(param.a_int, param.b_int));
}

template<typename InputType>
InputType randn(const size_t rows, 
                const size_t cols, 
                const typename std::enable_if_t<
                    coot::is_coot_type<InputType>::value>* = 0)
{
  return coot::randn<InputType>(rows, cols);
}

template<typename InputType>
InputType randu(const size_t rows,
                const size_t cols,
                const typename std::enable_if<
                    coot::is_coot_type<InputType>::value>* = 0)
{
  return coot::randu<InputType>(rows, cols);
}

#endif

template<typename InputType>
InputType randi(const size_t rows,
                const size_t cols,
                const arma::distr_param& param,
                const typename std::enable_if_t<
                    arma::is_arma_type<InputType>::value>* = 0)
{
  return arma::randi<InputType>(rows, cols, param);
}

template<typename InputType>
InputType randn(const size_t rows,
                const size_t cols,
                const typename std::enable_if_t<
                    arma::is_arma_type<InputType>::value>* = 0)
{
  return arma::randn<InputType>(rows, cols);
}

template<typename InputType>
InputType randu(const size_t rows,
                const size_t cols,
                const typename std::enable_if_t<
                    arma::is_arma_type<InputType>::value>* = 0)
{
  return arma::randu<InputType>(rows, cols);
}

} // namespace mlpack

#endif
