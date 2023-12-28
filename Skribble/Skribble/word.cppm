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
		explicit Words() noexcept = default;
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
		
	private:
		int m_id;
		std::string m_word;
		
	};
}