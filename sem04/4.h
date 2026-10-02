#pragma once

#include <vector>
#include <string>

// 4.1
std::vector<int> readf(const std::string& filename);

void countfor(const std::vector<int>& v);
void countalg(const std::vector<int>& v);

int sumalg(const std::vector<int>& v);
int sumnum(const std::vector<int>& v);
int sum10(const std::vector<int>& v);


// 4.2
int binacc(const std::vector<int>& v);

void finddups(const std::vector<int>& v1, const std::vector<int>& v2);

void dupfor(const std::vector<int>& v1, const std::vector<int>& v2);

void dupalg(const std::vector<int>& v1, const std::vector<int>& v2);