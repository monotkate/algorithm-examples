# Heaps
A heap is an easy way to access sorted data quickly.  They us a complete, binary tree that is stored in an array.  Upon inserting data, the key is automatically sorted into the correct portion of the heap.  There are two types of heaps.

# Min Heaps
A min heap is sorted so that the root, or 0 element, is the smallest element in the heap at all times.  When a new element is added, at all times the parent must be smaller than both child elements.  The new element is added at the end of the tree, and then bubbled up until it satisfies the parent/child relationship.  

When the min value is returned, it is removed from the tree, and replaced by the last child node in the heap.  This node is then bubbled down until the tree balance is restored.

# Max Heaps
A max heap is identical to a min heap, except that instead of the root element, or 0 element, being the smallest in the heap, it is the largest in the heap.  To satisfy the conditions of a max heap, the parent must always be larger than the two child nodes.
