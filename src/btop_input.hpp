/* Copyright 2021 Aristocratos (jakob@qvantnet.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

indent = tab
tab-size = 4
*/

#pragma once

#include <string>
#include <atomic>
#include <array>
#include <unordered_dense.h>
#include <deque>

using ankerl::unordered_dense::map;
using std::array;
using std::atomic;
using std::deque;
using std::string;

/* The input functions relies on the following std::cin options being set:
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	These will automatically be set when running Term::init() from btop_tools.cpp
*/

//* Functions and variables for handling keyboard and mouse input
namespace Input {

	struct Mouse_loc {
		int line, col, height, width;
	};

	//? line, col, height, width
	extern map<string, Mouse_loc> mouse_mappings;

	extern atomic<bool> interrupt;
	extern atomic<bool> polling;

	//* Mouse column and line position
	extern array<int, 2> mouse_pos;

	//* Last entered key
	extern deque<string> history;

	//* Poll keyboard & mouse input for <timeout> ms and return input availabilty as a bool
	bool poll(int timeout=0);

	//* Get a key or mouse action from input
	string get();

	//* Wait until input is available and return key
	string wait();

	//* Clears last entered key
	void clear();

	//* Process actions for input <key>
	void process(const string& key);

}
