module;
export module word;

import <string>;
import <vector>;
import <iostream>;
import <fstream>;
import <cstdlib>;
import <random>;
import <algorithm>;

namespace skribble
{
	export class Words
	{
	public:
		Words()=default;
		Words(const std::vector<std::string>& words);
		Words(const Words&) = delete;
		Words(Words&& listWords) noexcept = default;

		Words& operator=(const Words& words) = delete;
		Words& operator=(Words&& words)noexcept = default;
		~Words() = default;


		void setWords(const std::string& textFile);
		void setWords();

		std::vector<std::string> getWord(int nrRounds, int nrPlayers) const;


	private:
		std::vector<std::string> m_words;
	};
}