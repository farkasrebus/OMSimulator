/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-CurrentYear, Open Source Modelica Consortium (OSMC),
 * c/o Linköpings universitet, Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF GPL VERSION 3 LICENSE OR
 * THIS OSMC PUBLIC LICENSE (OSMC-PL) VERSION 1.2.
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THE OSMC PUBLIC LICENSE OR THE GPL VERSION 3,
 * ACCORDING TO RECIPIENTS CHOICE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from OSMC, either from the above address,
 * from the URLs: http://www.ida.liu.se/projects/OpenModelica or
 * http://www.openmodelica.org, and in the OpenModelica distribution.
 * GNU version 3 is obtained from: http://www.gnu.org/copyleft/gpl.html.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 */

#ifndef _OMS_COMPONENT_H_
#define _OMS_COMPONENT_H_

#include "ComRef.h"
#include "Types.h"
#include "Element.h"
#include <pugixml.hpp>

namespace oms3
{
  class System;

  class Component
  {
  public:
    virtual ~Component();

    const ComRef& getName() const {return cref;}
    oms_status_enu_t exportToSSD(pugi::xml_node& node) const;
    oms3::Element* getElement() {return &element;}
    oms3::Connector* getConnector(const ComRef &cref);
    oms_status_enu_t deleteResources();
    oms_status_enu_t getAllResources(std::vector<std::string>& resources) const {resources.push_back(path); return oms_status_ok;}

  protected:
    Component(const ComRef& cref, oms_component_enu_t type, System* parentSystem, const std::string& path);

    // stop the compiler generating methods copying the object
    Component(Component const&);            ///< not implemented
    Component& operator=(Component const&); ///< not implemented

  private:
    System* parentSystem;
    oms3::Element element;
    oms3::ComRef cref;
    oms_component_enu_t type;
    std::string path;
    std::vector<oms3::Connector*> connectors;
  };
}

#endif
