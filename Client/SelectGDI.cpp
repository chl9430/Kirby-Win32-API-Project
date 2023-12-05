#include "pch.h"
#include "SelectGDI.h"

#include "GameCore.h"

SelectGDI::SelectGDI(HDC _dc, PEN_TYPE _ePenType)
	: m_hDC{ _dc }
	, m_hDefaultPen{ nullptr }
	, m_hDefaultBrush{ nullptr }
{
	HPEN hPen = GameCore::GetInst()->GetPen(_ePenType);
	m_hDefaultPen = (HPEN)SelectObject(_dc, hPen); // ������ ���� ����Ʈ ������ ����
}

SelectGDI::SelectGDI(HDC _dc, BRUSH_TYPE _eBrushType)
	: m_hDC{ _dc }
	, m_hDefaultPen{ nullptr }
	, m_hDefaultBrush{ nullptr }
{
	HBRUSH hBrush = GameCore::GetInst()->GetBrush(_eBrushType);
	m_hDefaultBrush = (HBRUSH)SelectObject(_dc, hBrush); // ������ �귯���� ����Ʈ �귯���� ����
}

SelectGDI::~SelectGDI()
{
	SelectObject(m_hDC, m_hDefaultPen);
	SelectObject(m_hDC, m_hDefaultBrush);
}