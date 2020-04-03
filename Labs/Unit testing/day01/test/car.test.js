// const assert = require('assert');

// class Car {
//   constructor() {
//     this.model = 'standard';
//   }

//   park() {
//     return 'Parked';
//   }

//   drive() {
//     return 'Vroom!';
//   }
// }

// let car;
// beforeEach(() => {
//   console.log('Car created!');
//   car = new Car();
// });


// describe('Suite test for testing full functionality of `Car`', () => {
//   it('can park', () => {
//     car.model = 'tesla';
//     assert.equal(car.park(), 'Parked');
//   });

//   it('can car model', () => { 
//     assert.equal(car.model, 'standard');
//   });
// });