export module word;
import <string>;
import <vector>;
import <iostream>;
import <fstream>;

namespace skirbble
{
	export class Words
	{
	public:
		Words();
		Words(std::vector<std::string> words);
		~Words();

		void setWords(std::string textFile);

		std::string getWord();
	private:
		std::vector<std::string> m_words;
	};
}