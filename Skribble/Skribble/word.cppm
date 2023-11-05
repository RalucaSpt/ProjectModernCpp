export module word;
import <string>;
import <vector>;
import <iostream>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <random>;
import  <algorithm>;

namespace skribble
{
	export class Words
	{
	public:
		Words();
		Words(std::vector<std::string> words);
		~Words();

		void setWords(const std::string& textFile);
		void setWords();

		std::string getWord();
		
		void DeleteWord(std::string word);
			
	private:
		std::vector<std::string> m_words;
	};
}