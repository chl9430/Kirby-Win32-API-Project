#include "pch.h"
#include "GameTexture.h"

#include "GameCore.h"

GameTexture::GameTexture()
	: m_dc{}
	, m_hBit{}
	, m_bitInfo{}
{
}

GameTexture::~GameTexture()
{
	DeleteDC(m_dc);
	DeleteObject(m_hBit);
}

void GameTexture::Create(UINT _iWidth, UINT _iHeight)
{
	HDC mainDC = GameCore::GetInst()->GetMainDC(); // ���� DC�� �����´�.

	// ���� ���۸� �뵵�� ��Ʈ�ʰ� DC�� ����
	m_hBit = CreateCompatibleBitmap(mainDC, _iWidth, _iHeight);
	m_dc = CreateCompatibleDC(mainDC); // �׸��� �׸� �纻�� DC(Device Context)�� ����

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_dc, m_hBit); // �׸� �׸� Ÿ���� �ٲٰ�
	DeleteObject(hOldBit); // ����Ʈ�� ������ 1px ��Ʈ���� ����

	// ��Ʈ�� ����
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
}