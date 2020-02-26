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

#ifndef UTIL_H_
#define UTIL_H_

#include "glog/logging.h"

inline void InitLogger(char *argv[]) {
  FLAGS_logtostderr = 1;  // log to console
  google::InitGoogleLogging(argv[0]);
}

#define LOG_VALUE(value) #value << "=" << value << " "
#define LOG_NV(name, value) name << "=" << value << " "

#endif  // UTIL_H_
