This function I kept getting segmentation faults which can be attributed to my if statements if(root->left->data < root->data).
I did not know why this was the case, as root->left->right was not null. I tried debugging this by setting if statements before
that if statement to ensure that it would not enter if the right or left child was null. Besides this, I believe my recursive
function logic should be correct.
