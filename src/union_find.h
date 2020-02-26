//
// Copyright (C) 2020 Aaron
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https: //www.gnu.org/licenses/>.

#ifndef UNION_FIND_H_
#define UNION_FIND_H_

#include <memory>
#include <stdexcept>
#include "./util.h"

namespace alib {

class UnionFind {
 public:
  explicit UnionFind(uint64_t count) : count(count) {
    a = std::make_unique<InternalType[]>(count);
    weight_size = std::make_unique<uint64_t[]>(count);
    for (uint64_t i = 0; i < count; i++) {
      a[i] = i;
      weight_size[i] = 1;
    }
  }
  void Union(uint64_t p, uint64_t q) {
    uint64_t i = GetRoot(p);
    uint64_t j = GetRoot(q);
    if (i == j) return;  // already union
    if (weight_size[i] < weight_size[j]) {
      a[i] = j;
      weight_size[j] += weight_size[i];
      if (weight_size[j] == count) is_all_connected = true;
    } else {
      a[j] = i;
      weight_size[i] += weight_size[j];
      if (weight_size[i] == count) is_all_connected = true;
    }
  }
  bool IsConnected(uint64_t p, uint64_t q) { return GetRoot(p) == GetRoot(q); }
  bool IsAllConnected() { return is_all_connected; }

 private:
  typedef uint64_t InternalType;
  uint64_t count;
  bool is_all_connected = false;
  std::shared_ptr<InternalType[]> a;
  std::shared_ptr<uint64_t[]> weight_size;
  InternalType GetRoot(InternalType i) {
    while (i != a[i]) {
      a[i] = a[a[i]];
      i = a[i];
    }
    return i;
  }
};
}  // namespace alib

#endif  // UNION_FIND_H_
