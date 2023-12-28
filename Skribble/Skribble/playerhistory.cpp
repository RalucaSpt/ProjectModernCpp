module playerhistory;
using namespace skribble;

PlayerHistory::PlayerHistory(int id, int score, uint8_t placement, int userId)
	:m_id{id},m_score{score},m_placement{placement},m_userId{userId}
{
}

void skribble::PlayerHistory::SetId(int id)
{
	m_id = id;
}

void skribble::PlayerHistory::SetScore(int score)
{
	m_score = score;
}

void skribble::PlayerHistory::SetPlacement(uint8_t placement)
{
	m_placement = placement;
}

void skribble::PlayerHistory::SetUserId(int userId)
{
	m_userId = userId;
}

int skribble::PlayerHistory::GetId()
{
	return m_id;
}

int skribble::PlayerHistory::GetScore()
{
	return m_score;
}

uint8_t skribble::PlayerHistory::GetPlacement()
{
	return m_placement;
}

int skribble::PlayerHistory::GetUserId()
{
	return m_userId;
}
