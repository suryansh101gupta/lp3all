// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank_final{
    mapping (address => uint) balances;

    function deposit() public payable{
        balances[msg.sender]+=msg.value;
    }

    function withdraw(uint amount) public{
        require(amount<=balances[msg.sender],"Not Enough Funds");
        balances[msg.sender]-=amount;
        payable(msg.sender).transfer(amount);
    }

    function getBalance() public view returns (uint){
        return balances[msg.sender];
    }
}