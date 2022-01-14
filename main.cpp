#include <iostream>
#include <thread>
#include <fstream>
#include <chrono>
#include <set>
#include "generator.cpp"

using std::string;
using std::set;

class Tester{
	public:
		Tester(const string& data_path, int total)
		:data_path_(data_path), total_(total), correct_(0){
			load_data();
		}

		~Tester(){}
		
		void get_test(){
			for(int i = 0; i < total_; i ++){
				string answer;

				vector<string>& tmp = generator_.get_words();
				string target = *select_random(tmp.begin(), tmp.end());

				//GUI
				system("clear");

				printf("[TOTAL/PROGRESS/ANSWER] %d/%d/%d\n", total_, i+1, correct_);

				std::cout << i+1 << ". " << target << std::endl;
				getline(std::cin, answer, '\n');

				int score =  generator_.is_answer(target, answer);
				correct_ += score;
				
				if(score == 0){
					std::cout << "X\n";
					wrongs_.insert(target);
				}
				else{
					std::cout << "O\n";
				}

				for(const auto& mean: generator_.get_means(target)){
					std::cout << ">>" << mean << "\n";
				}
				
				
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				
				system("clear");
				printf("[TOTAL/ANSWER] %d/%d\n", total_, correct_);
				
				if(total_ != correct_) std::cout << "### Wrong Word ###\n";
				else std::cout << "Congraturation!\n";

				for(const auto& item: wrongs_){
					std::cout << item << "\t";
					if(item.length() < 8) std::cout <<"\t";
					std::cout << "[";

					for(const auto& mean: generator_.get_means(item)){
						std::cout << mean << ", ";
					}
					std::cout << "]\n";
				}

			}
		}

	private:
		void load_data(){
			std::fstream in(data_path_);
			std::string tmp;

			while(in){
				getline(in, tmp);
				rtrim(tmp, ", ");

				generator_.insert_data(tmp);
			}
			return;
		}

		string data_path_;
		Generator generator_;

		int total_;
		int correct_;
		set<string> wrongs_;
};


int main(int args, const char* argv[]){
	int base = 10;
	if(args == 2) base = stoi(string(argv[1]));
	
	Tester test("data/18.data", base);
	
	test.get_test();
	
	return 0;
}
