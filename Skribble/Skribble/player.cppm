module;
export module player;
import <iostream>;

namespace skribble {

	export class Player {

	public:
		Player();
		Player(uint16_t IdPlayer, uint16_t score);
		Player(const Player& player);

		~Player();

		Player& operator= (const Player& player);

		uint16_t GetIdPlayer() const;
		uint16_t GetScore() const;
		std::string GetName() const;
		bool GetIsDrawing() const;

		void SetIsDrawing(bool isDrawing);
		void setName(const std::string& name);
		
	private:
		uint16_t m_idPlayer;
		uint16_t m_score;
		bool m_isDrawing;
		std::string m_name;
		//std::string m_name;
	};
}