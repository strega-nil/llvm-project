//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// REQUIRES: std-at-least-c++23

// constexpr const Iterator& base() const & noexcept;
// constexpr Iterator base() &&;

#include <cassert>
#include <iterator>
#include <utility>

#include "test_macros.h"

constexpr bool test() {
  int buffer[] = {1, 2, 3};
  std::basic_const_iterator<int*> iter(buffer);

  ASSERT_SAME_TYPE(decltype(iter.base()), int* const&);
  ASSERT_NOEXCEPT(iter.base());
  assert(iter.base() == buffer);

  ASSERT_SAME_TYPE(decltype(std::move(iter).base()), int*);
  assert(std::move(iter).base() == buffer);

  return true;
}

int main(int, char**) {
  test();
  static_assert(test());

  return 0;
}
