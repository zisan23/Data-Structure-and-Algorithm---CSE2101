struct Node {
  int data;
  Node* next;
};

Node* merge(Node* list1, Node* list2, Node* list3) {
  Node dummy;
  Node* tail = &dummy;

  while (list1 != nullptr || list2 != nullptr || list3 != nullptr) {
    if (list1 != nullptr && (list2 == nullptr || list1->data <= list2->data) && (list3 == nullptr || list1->data <= list3->data)) {
      tail->next = list1;
      list1 = list1->next;
    } else if (list2 != nullptr && (list3 == nullptr || list2->data <= list3->data)) {
      tail->next = list2;
      list2 = list2->next;
    } else {
      tail->next = list3;
      list3 = list3->next;
    }
    tail = tail->next;
  }

  return dummy.next;
}
