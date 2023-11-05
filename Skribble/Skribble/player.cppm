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

		uint16_t GetIdPlayer();
		uint16_t GetScore();
		std::string GetName() const;
		bool GetIsDrawing();

		void SetIsDrawing(bool isDrawing);
		void SetName(const std::string& name);
		
	private:
		uint16_t m_idPlayer;
		uint16_t m_score;
		bool m_isDrawing;
		std::string m_name;
	};
}