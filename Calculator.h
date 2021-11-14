#pragma once
#include<iostream>
#include "String.h"
#include "List.h"

class Calculator{
   private : 
      List<String> tokens;
      int errCode;                  // �߻��� �����ڵ� �� : 0 -> ���� ���� , �ٸ� �� -> ���� ����
      int value;                     // ���� ��
      String postfix;              // ����ǥ��� = ���� �������� �ʱ�ȭ

      int makePostFix(const char *expr);         // postfix �� �����ϴ� �Լ� : 
                                       // ���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ 
                                       // �������� postfix ������ ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)
      int evaluation();            // postfix �� ����ϴ� �Լ� : 
                                       // ���� ���� ����, ���� ���°�� 0, ������ �ִ� ���, 1�� ��ȯ
                                       // ���� ���� value �� ����, ������ ������ �ڵ带 errCode �� ���� (�����ڵ�� ���ڰ� ����)

  public : 
      int getErrorCode();                       // �����ڵ� ��ȯ
      int setExpression(const char* expr);      // expr�� ���޵� ����(����ǥ���)�� postfix�� �����ϰ� ����ϴ� �Լ�      
                                                // ���� ���°��, 0, ������ �ִ� ���, 1�� ��ȯ 
       String getPostFix();                     // ��ȯ�� ����ǥ����� ��ȯ   --> ������ ������� ���ʰ��� ������ ����
       int getValue();                          // ���� �������� --> ���ܹ߻�
                                                // ���� �������� --> ����� ����

};