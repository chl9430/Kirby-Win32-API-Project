#pragma once

class GameRes
{
private:
    wstring m_strKey; // ���ҽ� Ű ��
    wstring m_strRelativePath; // ���ҽ� ��� ���

public:
    const wstring& GetKey()
    {
        return m_strKey;
    }

    void SetKey(const wstring& _strKey)
    {
        m_strKey = _strKey;
    }

    const wstring& GetRelativePath()
    {
        return m_strRelativePath;
    }

    void SetRelativePath(const wstring& _strPath)
    {
        m_strRelativePath = _strPath;
    }

    GameRes();
    virtual ~GameRes();
};

