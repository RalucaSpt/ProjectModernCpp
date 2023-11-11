export module player;
import <iostream>;

namespace skribble {
	enum class DrawingStatus { NotDrawing, Drawing };
	export class Player {

	public:
		Player();
		Player(uint16_t IdPlayer, uint16_t score, const std::string& m_name);
		Player(const Player& player);

		~Player();

		Player& operator= (const Player& player);

		uint16_t GetIdPlayer() const;
		uint16_t GetScore() const;
		std::string GetName() const;
		bool GetIsDrawing() const;

		void SetIsDrawing(bool isDrawing);
		void setName(const std::string& name);
		// Score management
		void AddScore(uint16_t points);
		void SubtractScore(uint16_t points);
		void ResetScore();

		// Serialization (example using string, but JSON/XML/other could be used)
		std::string Serialize() const;
		static Player Deserialize(const std::string& data);

		// Friend functions
		friend std::ostream& operator<<(std::ostream& os, const Player& player);
		friend std::istream& operator>>(std::istream& is, Player& player);

		// Equality and Comparison
		bool operator==(const Player& other) const;
		bool operator!=(const Player& other) const;
		
	private:
		uint16_t m_idPlayer;
		uint16_t m_score;
		DrawingStatus m_drawingStatus;
		std::string m_name;
	};
}