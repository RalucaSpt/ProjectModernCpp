module playerhistory;
using namespace skribble;

PlayerHistory::PlayerHistory(uint32_t id, int16_t score, uint8_t placement, uint32_t userId)
	:m_id{id},m_score{score},m_placement{placement},m_userId{userId}
{
}

void skribble::PlayerHistory::SetId(uint32_t id)
{
	m_id = id;
}

void skribble::PlayerHistory::SetScore(int16_t score)
{
	m_score = score;
}

void skribble::PlayerHistory::SetPlacement(uint8_t placement)
{
	m_placement = placement;
}

void skribble::PlayerHistory::SetUserId(uint32_t userId)
{
	m_userId = userId;
}

uint32_t skribble::PlayerHistory::GetId()const
{
	return m_id;
}

int16_t skribble::PlayerHistory::GetScore()const
{
	return m_score; 
}

uint8_t skribble::PlayerHistory::GetPlacement()const
{
	return m_placement;
}

uint32_t skribble::PlayerHistory::GetUserId()const
{
	return m_userId;
}
