export module word;
import <string>;
import <vector>;
namespace skirbble
{
	export class Words
	{
	public:
		Words();
		Words(std::vector<std::string> words);
		~Words();
	private:
		std::vector<std::string> m_words;
	};
}