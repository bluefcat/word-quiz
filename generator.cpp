#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "util.cpp"

using std::string;
using std::vector;
using std::map;

//regex
using std::regex;
using std::smatch;

class Generator{
	public:
		Generator(){};
		~Generator(){};

		void insert_data(string data){
			regex re("(\\S*)\\s*:\\s*\\[(.*)\\]");
			smatch match;

			if(std::regex_match(data, match, re)){
				string word(match[1].str());
				string means(match[2].str());
				
				//get word's mean
				string::size_type start = 0;
				string::size_type end = 0;
				
				printf("%s\n", means.c_str());
				do{
					end = means.find(",", end+1);
					string mean = means.substr(start, end-start);
					trim(mean);

					//insert data
					word_.push_back(word);
					data_[word].push_back(std::move(mean));

					start = end+1;
				}while(end != string::npos);
			}
			
		}
		
		bool is_answer(const string& word, const string& answer){
			bool result = false;

			for(const auto& mean: data_[word]){
				if(mean == answer){
					result = true;
					break;
				}
			}

			return result;
		}
		
		vector<string>& get_words(){
			return word_;
		}

		vector<string>& get_means(const string& word){
			return data_[word];
		}

	private:
		vector<string> word_;
		map<string, vector<string>> data_;
};

#ifdef TEST
int main(){
	printf("This is [%s] test section\n", __FILE__);

	Generator generator;

	generator.insert_data("Hello : [안녕, 반가워, 사랑해]");
	generator.insert_data("one :  [1, 하나, 일, one, two]");

	std::cout << "Hello's mean===\n";
	for(const auto& mean: generator.get_means("Hello")){
		//std::cout << mean << std::endl;
	}
	
	std::cout << "one's means===\n";
	for(const auto& mean: generator.get_means("one")){
		//std::cout << mean << std::endl;
	}

	printf("This is [%s] test section\n", __FILE__);
	return 0;
}
#endif


