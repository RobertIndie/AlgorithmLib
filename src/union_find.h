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

namespace alib {

template <bool FuncAllConnected = false>
class UnionFind {
 public:
  explicit UnionFind(uint64_t count) : count(count) {
    a = std::make_unique<InternalType[]>(count);
    weight_size = std::make_unique<uint64_t[]>(count);
    if constexpr (FuncAllConnected) {
      all_connect_check = std::make_unique<int8_t[]>(count - 1);
    }
    for (uint64_t i = 0; i < count; i++) {
      a[i] = i;
      weight_size[i] = 1;
      if constexpr (FuncAllConnected) {
        all_connect_check[i] = 0;
      }
    }
  }
  void Union(uint64_t p, uint64_t q) {
    uint64_t i = GetRoot(p);
    uint64_t j = GetRoot(q);
    if (i == j) return;  // already union
    if (weight_size[i] < weight_size[j]) {
      a[i] = j;
      weight_size[j] += weight_size[i];
    } else {
      a[j] = i;
      weight_size[i] += weight_size[j];
    }
    if constexpr (FuncAllConnected) {
#define CHECK_ALL_CONNECT(node)                                              \
  {                                                                          \
    if (node != 0 && all_connect_check[node] != 1 && IsConnected(0, node)) { \
      all_connect_count++;                                                   \
      all_connect_check[node] = 1;                                           \
    }                                                                        \
  }
      CHECK_ALL_CONNECT(p);
      CHECK_ALL_CONNECT(q);
    }
  }
  bool IsConnected(uint64_t p, uint64_t q) { return GetRoot(p) == GetRoot(q); }
  bool IsAllConnected() {
    if constexpr (FuncAllConnected) {
      return count == all_connect_count;
    }
    throw;
  }

 private:
  typedef uint64_t InternalType;
  uint64_t count;
  std::shared_ptr<InternalType[]> a;
  std::shared_ptr<uint64_t[]> weight_size;
  // FuncAllConnected
  std::shared_ptr<int8_t[]> all_connect_check;  // index left shift 1
  uint64_t all_connect_count = 0;
  void UpdateAllConnect(uint64_t p) {
    if (p != 0 && all_connect_check[p] != 1 && IsConnected(0, p)) {
      all_connect_count++;
      all_connect_check[p] = 1;
    }
  }
  InternalType GetRoot(InternalType i) {
    while (i != a[i]) {
      a[i] = a[a[i]];
      if (i == 0) {
        for (int j = 0; j < count; j++) {
          if (a[j] == a[0] && all_connect_check[j] != 1) {
            all_connect_check[j] = 1;
            all_connect_count++;
          }
        }
      }
      UpdateAllConnect(i);
      i = a[i];
    }
    return i;
  }
};
}  // namespace alib

#endif  // UNION_FIND_H_
