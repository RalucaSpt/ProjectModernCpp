export module player;
import <iostream>;

namespace skribble {
	
	
	export class Player {
	private:
		enum class DrawingStatus 
		{
			NotDrawing,
			Drawing
		};
	public:
		Player() = default;
		Player(int IdPlayer, uint16_t score, const std::string& name);
		Player(const int& IdPlayer,  const std::string& name,const std::string& password);
		Player(const Player& player) = default;
		Player(Player&& player) = default;
		Player& operator= (const Player& player);
		Player& operator= (Player&& player) noexcept = default;
	
		~Player() noexcept = default;

	
		int GetIdPlayer() const;
		std::string GetName() const;
		std::string GetPassword() const;
		uint16_t GetScore() const;
		uint16_t GetCorrectAnswerTime() const;
		void SetCorrectAnswerTime(uint8_t seconds);

		void SetId(const int& id);
		void SetName(const std::string& name);
		void SetPassword(const std::string& password);
		void SetScore(uint16_t score);

		bool IsDrawing() const;
		
		// Score management
		void AddScore(uint16_t points,int nrPlayers);
		void SubtractScore(uint16_t points, bool hasGuessed);
		void ResetScore();

		// Friend functions
		friend std::ostream& operator<<(std::ostream& os, const Player& player);
		friend std::istream& operator>>(std::istream& is, Player& player);

		//// Equality and Comparison	
		//bool operator==(const Player& other) const;
		//bool operator!=(const Player& other) const;

		void StartDrawing();
		void StopDrawing();
		
	private:
		int m_idPlayer;

		std::string m_name;
		std::string m_password;
	
		uint16_t m_score;
		uint8_t m_correctAnswerTime; // de la 0 la 60
		DrawingStatus m_isDrawing;

		bool IsValidName(const std::string& name);
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

	void Player::StartDrawing() {
		m_isDrawing = DrawingStatus::Drawing;
		std::cout << "Jucătorul " << this->m_name << " începe să deseneze." << std::endl;
	}
	
	void Player::StopDrawing() {
		m_isDrawing = DrawingStatus::NotDrawing;
	}
	
}