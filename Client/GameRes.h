#pragma once

class GameRes
{
private:
    wstring m_strKey; // ���ҽ� Ű ��
    wstring m_strRelativePath; // ���ҽ� ��� ���

public:
    void SetKey(const wstring& _strKey)
    {
        m_strKey = _strKey;
    }

    GameRes();
    virtual ~GameRes();
};

