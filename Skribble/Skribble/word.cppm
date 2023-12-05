module;
export module word;


import <string>;
import <vector>;
import <iostream>;
import <cstdlib>;
import <random>;
import <algorithm>;

#include <fstream>

namespace skribble {
	export class Words
	{
	public:
		Words() noexcept = default;
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