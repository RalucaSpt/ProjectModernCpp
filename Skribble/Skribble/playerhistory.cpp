module playerhistory;
using namespace skribble;

PlayerHistory::PlayerHistory(int id, int score, int placement, int userId)
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

void skribble::PlayerHistory::SetPlacement(int placement)
{
	m_placement = placement;
}

void skribble::PlayerHistory::SetUserId(int userId)
{
	m_userId = userId;
}

int skribble::PlayerHistory::GetId()const
{
	return m_id;
}

int skribble::PlayerHistory::GetScore()const
{
	return m_score; 
}

int skribble::PlayerHistory::GetPlacement()const
{
	return m_placement;
}

int skribble::PlayerHistory::GetUserId()const
{
	return m_userId;
}
