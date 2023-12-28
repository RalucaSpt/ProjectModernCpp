export module playerhistory;
import <iostream>;

namespace skribble
{
	export class PlayerHistory
	{
	public:
		PlayerHistory()=default;
		PlayerHistory(int id, int score, int placement,int userId);
		void SetId(int id);
		void SetScore(int score);
		void SetPlacement(int placement);
		void SetUserId(int userId);

		int GetId()const; 
		int GetScore()const;
		int GetPlacement()const;
		int GetUserId()const;
	private:
		int m_id;
		int m_score;
		int m_placement;
		int m_userId;
	};
}
