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
	/*public:
		Words() noexcept = default;
		Words(const std::vector<std::string>& words);
		Words(const Words&) = delete;
		Words(Words&& listWords) noexcept = default;

		Words& operator=(const Words& words) = delete;
		Words& operator=(Words&& words)noexcept = default;

		~Words() = default;*/
	public:
		Words() noexcept = default;
		Words(int id, std::string word)
			:m_id{id},m_word{word}
		{
		}
		std::string GetWord() const;
		int GetId() const;
		void SetWord(const std::string& word);
		void SetId(const int& id);
		/*void setWords(const std::string& textFile);
		void setWords();*/

		std::vector<std::string> getWord(int nrRounds, int nrPlayers) const;


	private:
		int m_id;
		std::string m_word;
		//std::vector<std::string> m_words;
	};
}