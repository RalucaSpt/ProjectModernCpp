export module word;
import <string>;
import <vector>;
import <iostream>;
import <fstream>;
import <cstdlib>;
import <ctime>;
import <random>;

namespace skribble
{
	export class Words
	{
	public:
		Words();
		Words(std::vector<std::string> words);
		~Words();

		void setWords(const std::string& textFile);

		std::string getWord();
		
			
	private:
		std::vector<std::string> m_words;
	};
}