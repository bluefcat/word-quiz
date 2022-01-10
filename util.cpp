#pragma once
#include <string>
#include <random>
#include <iterator>

template<typename Iter, typename RandomGenerator>
Iter select_random(Iter start, Iter end, RandomGenerator& g){
	std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
	std::advance(start, dis(g));

	return start;
}

template<typename Iter>
Iter select_random(Iter start, Iter end){
	static std::random_device rd;
	static std::mt19937 gen(rd());

	return select_random(start, end, gen);
}

inline std::string& ltrim(std::string& str, const char* t = " \t\n\r\f\v"){
	str.erase(0, str.find_first_not_of(t));
	return str;
}

inline std::string& rtrim(std::string& str, const char* t = " \t\n\r\f\v"){
	str.erase(str.find_last_not_of(t)+1);
	return str;
}

inline std::string& trim(std::string& str, const char* t = " \t\n\r\f\v"){
	return ltrim(rtrim(str, t), t);
}
