package com.atguigu.springboot.service;

import com.atguigu.springboot.bean.Employee;
import com.atguigu.springboot.mapper.EmployeeMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author LC
 * @Date 2020/8/6 21:36
 * @Version 1.0
 */
@Service
public class EmployeeService {

    @Autowired
    EmployeeMapper employeeMapper;
    public Employee getEmp(Integer id){
        return employeeMapper.getEmpById(id);
    }
}
