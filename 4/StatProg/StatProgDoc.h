// StatProgDoc.h :  CStatProgDoc ��Ľӿ�
//


#pragma once

class CStatProgDoc : public CDocument
{
protected: // �������л�����
	CStatProgDoc();
	DECLARE_DYNCREATE(CStatProgDoc)

// ����
public:

// ����
public:

// ��д
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// ʵ��
public:
	virtual ~CStatProgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


