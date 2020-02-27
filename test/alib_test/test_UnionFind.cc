//
// Copyright (C) 2019 Linkworld Open Team
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

#include <fstream>
#include <iostream>
#include "./union_find.h"
#include "gtest/gtest.h"

TEST(UnionFind, SocialNetwork) {
  std::ifstream logfile("./social_network/log.txt");
  alib::UnionFind uf(10);
  int count = 0;
  int ts, p, q;
  while (logfile >> ts >> p >> q) {
    uf.Union(p, q);
    if (uf.IsAllConnected()) break;
  }
  EXPECT_EQ(ts, 9);
  logfile.close();
}

TEST(UnionFind, Max) {
  alib::UnionFind uf(10);
  EXPECT_EQ(uf.Find(0), 0);
  uf.Union(0, 1);
  uf.Union(2, 1);
  EXPECT_EQ(uf.Find(0), 2);
}
