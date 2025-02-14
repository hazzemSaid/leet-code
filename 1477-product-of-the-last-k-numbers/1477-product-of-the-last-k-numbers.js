var ProductOfNumbers = function() {
    this.products = [1]; // Initialize with a cumulative product starting at 1
};

/** 
 * @param {number} num
 * @return {void}
 */
ProductOfNumbers.prototype.add = function(num) {
    if (num === 0) {
        this.products = [1];
    } else {
        this.products.push(this.products[this.products.length - 1] * num);
    }
};

/** 
 * @param {number} k
 * @return {number}
 */
ProductOfNumbers.prototype.getProduct = function(k) {
    const n = this.products.length;
    if (k >= n) {
        return 0;
    }
    return this.products[n - 1] / this.products[n - 1 - k];
};

/** 
 * Your ProductOfNumbers object will be instantiated and called as such:
 * var obj = new ProductOfNumbers()
 * obj.add(num)
 * var param_2 = obj.getProduct(k)
 */
