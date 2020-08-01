package com.atguigu.springboot.controller;

import com.atguigu.springboot.dao.DepartmentDao;
import com.atguigu.springboot.dao.EmployeeDao;
import com.atguigu.springboot.entities.Department;
import com.atguigu.springboot.entities.Employee;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

import java.util.Collection;

/**
 * @Author LC
 * @Date 2020/7/31 21:36
 * @Version 1.0
 */

@Controller

public class EmployeeController {
    @Autowired
    EmployeeDao employeeDao;

    @Autowired
    DepartmentDao departmentDao;

    @GetMapping("/emps")
    //查询所有员工，返回列表页面
    public String list(Model model){
        Collection<Employee> employees = employeeDao.getAll();

        //放在请求域中
        model.addAttribute("emps",employees);
        //thymeleaf默认拼串
        return "/emp/list";
    }

    @GetMapping("/emp")
    public String toAddPage(Model model){
        //来到添加页面,查出所有的部门在页面显示
        Collection<Department> departments = departmentDao.getDepartments();
        model.addAttribute("depts",departments);
        return "/emp/add";

    }

    //员工添加
    //springmvc自动将请求参数和入参属性进行一一绑定：要求请求参数的名字和javabean中的属性名一致
    @PostMapping("/emp")
    public String addEmp(Employee employee){

        //来到员工列表页面
        System.out.println("员工信息"+employee);
        //保存员工
        employeeDao.save(employee);
        //redirect重定向 /代表当前项目路径
        //forward转发
        return "redirect:/emps";
    }


    //来到修改页面，查出当前员工，在页面回显
    @GetMapping("/emp/{id}")
    public String toEditPage(@PathVariable("id") Integer id,Model model){
        Employee employee = employeeDao.get(id);
        model.addAttribute("emp",employee);

        //页面显示所有的部门列表
        Collection<Department> departments = departmentDao.getDepartments();
        model.addAttribute("depts",departments);
        //回到修改页面(add是修改添加二合一的页面)
        return "/emp/add";
    }

    //员工修改,需要提供员工id
    @PutMapping("emp")
    public String updateEmployee(Employee employee){
        employeeDao.save(employee);
        return "redirect:/emps";
    }

    //员工删除
    @DeleteMapping("/emp/{id}")
    public String deleteEmployee(@PathVariable("id") Integer id){
         employeeDao.delete(id);
         return "redirect:/emps";

    }
}
