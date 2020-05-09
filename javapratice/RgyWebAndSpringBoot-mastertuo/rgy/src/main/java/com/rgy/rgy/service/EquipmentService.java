package com.rgy.rgy.service;

import com.rgy.rgy.bean.Equipment;
import com.rgy.rgy.bean.EquipmentType;
import com.rgy.rgy.bean.PowerPlant;
import com.rgy.rgy.bean.beanToAndroid.EquipmentToA;
import com.rgy.rgy.dao.EquipmentDao;
import com.rgy.rgy.dao.EquipmentTypeDao;
import com.rgy.rgy.dao.PowerPlantDao;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.parameters.P;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author: gaoyk
 * @Date: 2019/11/1 23:22
 */

@Service
public class EquipmentService{
    @Autowired
    EquipmentDao equipmentDao;

    @Autowired
    EquipmentTypeDao equipmentTypeDao;

    @Autowired
    PowerPlantDao powerPlantDao;

    public Boolean add(Equipment equipment) {
        equipment.setInfoState(0);
        Equipment equipment1 = equipmentDao.save(equipment);
        if(equipment1 != null){
            return true;
        }else{
            return false;
        }
    }

    public List<Equipment> findAll(){
        return equipmentDao.findAll();
    }

    public List<EquipmentToA> findEquipments(){
        List<EquipmentToA> equipmentToAS = new ArrayList<>();
        List<Equipment> equipmentList = equipmentDao.findAll();
        for (int i = 0;i < equipmentList.size();i++){
            int a = equipmentList.get(i).getPowerPlantID();
            PowerPlant powerPlant = powerPlantDao.findByid(a);
            EquipmentToA equipmentToA = new EquipmentToA();
            equipmentToA.setEquipmentId(equipmentList.get(i).getEquipmentId());
            equipmentToA.setEquipmentModel(equipmentList.get(i).getEquipmentModel());
            equipmentToA.setEquipmentName(equipmentList.get(i).getEquipmentName());
            equipmentToA.setEquipmentTypeID(equipmentList.get(i).getEquipmentTypeID());
            equipmentToA.setInfoState(equipmentList.get(i).getInfoState());
            equipmentToA.setManuFactorer(equipmentList.get(i).getManuFactorer());
            equipmentToA.setPicUrl1(equipmentList.get(i).getPicUrl1());
            equipmentToA.setPicUrl2(equipmentList.get(i).getPicUrl2());
            equipmentToA.setPowerPlantID(equipmentList.get(i).getPowerPlantID());
            equipmentToA.setPowerPlantName(powerPlant.getPowerPlantName());
            equipmentToA.setRemarks(equipmentList.get(i).getRemarks());
            equipmentToA.setRunDate(equipmentList.get(i).getRunDate());
            equipmentToA.setVoltageLevel(equipmentList.get(i).getVoltageLevel());
            equipmentToAS.add(equipmentToA);
        }
        return equipmentToAS;
    }

    public Map<Equipment, EquipmentType> findByCondition(String equipmentName,
                                           String equipmentTypeID,
                                           String voltageLevel,
                                           Integer powerPlantID) {
        List<Equipment> equipmentList = equipmentDao.findbyCondition(equipmentName,equipmentTypeID,voltageLevel,powerPlantID);;
        Map<Equipment, EquipmentType> map = new LinkedHashMap<>();
        for(int i = 0; i < equipmentList.size(); i++){
            int a = equipmentList.get(i).getEquipmentTypeID();
            EquipmentType equipmentType = equipmentTypeDao.findByEquipmentTypeID(a);
            map.put(equipmentList.get(i),equipmentType);
        }
        return map;
    }

    public Map<Equipment, EquipmentType> findByPowerPlantId(Integer powerPlantID){
        List<Equipment> equipmentList = equipmentDao.findByPowerPlantID(powerPlantID);
        Map<Equipment, EquipmentType> map = new LinkedHashMap<>();
        for(int i = 0; i < equipmentList.size(); i++){
            int a = equipmentList.get(i).getEquipmentTypeID();
            EquipmentType equipmentType = equipmentTypeDao.findByEquipmentTypeID(a);
            map.put(equipmentList.get(i),equipmentType);
        }
        return map;
    }

    public boolean update(Equipment equipment) {
        Equipment equipment1 = equipmentDao.findByEquipmentId(equipment.getEquipmentId());
        if(equipment1 == null){
            return false;
        }
        equipment1 = equipment;
        if(equipmentDao.save(equipment1) != null){
            return true;
        }else{
            return false;
        }
    }

    public boolean delete(Integer equipmentId) {
        Equipment equipment = equipmentDao.findByEquipmentId(equipmentId);
        if(equipment != null){
            equipment.setEquipmentId(1);
            equipmentDao.save(equipment);
            return true;
        }else{
            return false;
        }
    }

    public List<Equipment> findById(Integer powerPlantID) {
        return equipmentDao.findByPowerPlantID(powerPlantID);
    }

    public Equipment findByEquipmentId(Integer equipmentId) {
        return equipmentDao.findByEquipmentId(equipmentId);
    }
}
