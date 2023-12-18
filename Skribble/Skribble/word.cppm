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
		Words(int id, std::string word);
		Words(const Words&) = delete;
		Words(Words&& word) noexcept = default;

		Words& operator=(const Words& words) = delete;
		Words& operator=(Words&& words)noexcept = default;

		~Words() = default;

		std::string GetWord() const;
		int GetId() const;
		void SetWord(const std::string& word);
		void SetId(const int& id);
		
		/*std::vector<std::string> getWord(const int& nrRounds, const int& nrPlayers,const Database& db) const;*/


	private:
		int m_id;
		std::string m_word;
		//std::vector<std::string> m_words;
	};
}