export module player;
import <iostream>;

namespace skribble {
	
	// enum class DrawingStatus { NotDrawing, Drawing };
	export class Player {
	private:
		enum class DrawingStatus 
		{
			NotDrawing,
			Drawing
		};
	public:
		Player() = default;
		Player(uint16_t IdPlayer, uint16_t score, const std::string& m_name);
		Player(const Player& player) = default;
		Player(Player&& player) = default;
		Player& operator= (const Player& player);
		Player& operator= (Player&& player) noexcept = default;
		

		~Player();


		uint16_t GetIdPlayer() const;
		uint16_t GetScore() const;
		uint16_t GetCorrectAnswerTime();
		std::string GetName() const;
		DrawingStatus GetIsDrawing() const;
		bool guessedWord();

		void SetIsDrawing(DrawingStatus isDrawing);
		void setName(const std::string& name);
		// Score management
		void AddScore(uint16_t points,int nrPlayers);
		void SubtractScore(uint16_t points);
		void ResetScore();

		// Serialization (example using string, but JSON/XML/other could be used)
		//std::string Serialize() const;
		//static Player Deserialize(const std::string& data);

		// Friend functions
		friend std::ostream& operator<<(std::ostream& os, const Player& player);
		friend std::istream& operator>>(std::istream& is, Player& player);

		// Equality and Comparison	
		bool operator==(const Player& other) const;
		bool operator!=(const Player& other) const;
		
	private:
		//skribble::match* m_match = nullptr;
		uint16_t m_idPlayer;
		uint16_t m_score;
		uint8_t m_correctAnswerTime; // de la 0 la 60
		DrawingStatus m_drawingStatus;
		std::string m_name;
	};


	std::ostream& operator<<(std::ostream& os, const Player& player)
	{
		os <<"Id player: "<< player.m_idPlayer<<" nume: "<< player.m_name;
		return os;
	}
	std::istream& operator>>(std::istream& is, Player& player)
	{
		is >> player.m_idPlayer >> player.m_name;
		return is;
	}
}