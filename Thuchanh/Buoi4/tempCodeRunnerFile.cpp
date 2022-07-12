if(root != NULL) {
        DuyetCayLNR(root->pLeft);
        cout << root->value << '\t' << &(root->value) << '\t';
        cout << "pLeft: " << &(root->pLeft->value) << '\t' << '\t';
        cout << "pRight: " << &(root->pRight->value) << endl;
        DuyetCayLNR(root->pRight);
    }