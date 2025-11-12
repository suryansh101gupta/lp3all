// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentDataFinal{
    struct Student{
        uint id;
        string name;
        uint age;
        string course;
    }
    Student[] private students;

    function addStudents(uint _id, string memory _name, uint _age, string memory _course) public {
        students.push(Student(_id,_name,_age,_course));
    }

    function getCount() public view returns (uint) {
        return students.length;
    }

    function getStudent(uint index) public view returns (uint, string memory, uint,string memory){
        require(index<students.length,"Invalid Index");
        Student memory s = students[index];
        return (s.id,s.name,s.age,s.course);
    }
}