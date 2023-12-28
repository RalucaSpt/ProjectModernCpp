export module playerhistory;
import <iostream>;

namespace skribble
{
	export class PlayerHistory
	{
	public:
		PlayerHistory()=default;
		PlayerHistory(int id, int score, uint8_t placement,int userId);
		void SetId(int id);
		void SetScore(int score);
		void SetPlacement(uint8_t placement);
		void SetUserId(int userId);

		int GetId(); 
		int GetScore();
		uint8_t GetPlacement();
		int GetUserId();
	private:
		int m_id;
		int m_score;
		uint8_t m_placement;
		int m_userId;
	};
}
