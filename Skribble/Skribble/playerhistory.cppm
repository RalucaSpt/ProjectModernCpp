export module playerhistory;
import <iostream>;

namespace skribble
{
	export class PlayerHistory
	{
	public:
		PlayerHistory()=default;
		PlayerHistory(uint32_t id, int16_t score, uint8_t placement, uint32_t userId);
		void SetId(uint32_t id);
		void SetScore(int16_t score);
		void SetPlacement(uint8_t placement);
		void SetUserId(uint32_t userId);

		uint32_t GetId()const;
		int16_t GetScore()const;
		uint8_t GetPlacement()const;
		uint32_t GetUserId()const;
	private:
		uint32_t m_id;
		int16_t m_score;
		uint8_t m_placement;
		uint32_t m_userId;
	};
}
