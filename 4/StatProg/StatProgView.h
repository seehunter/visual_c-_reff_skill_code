// StatProgView.h : CStatProgView ��Ľӿ�
//


#pragma once


class CStatProgView : public CView
{
protected: // �������л�����
	CStatProgView();
	DECLARE_DYNCREATE(CStatProgView)

// ����
public:
	CStatProgDoc* GetDocument() const;

// ����
public:

// ��д
	public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CStatProgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // StatProgView.cpp �ĵ��԰汾
inline CStatProgDoc* CStatProgView::GetDocument() const
   { return reinterpret_cast<CStatProgDoc*>(m_pDocument); }
#endif

