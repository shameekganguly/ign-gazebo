/*
 * Copyright (C) 2018 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include "ignition/gazebo/components/Material.hh"

using namespace ignition;
using namespace gazebo;
using namespace components;

class ignition::gazebo::components::MaterialPrivate
{
  /// \brief Constructor.
  /// \param[in] _material Material data.
  public: explicit MaterialPrivate(const sdf::Material &_material)
          : material(_material)
  {
  }

  /// \brief The material data.
  public: sdf::Material material;
};

//////////////////////////////////////////////////
Material::Material(const sdf::Material &_material)
  : dataPtr(std::make_unique<MaterialPrivate>(_material))
{
}

//////////////////////////////////////////////////
Material::~Material()
{
}

//////////////////////////////////////////////////
Material::Material(const Material &_material)
  : dataPtr(std::make_unique<MaterialPrivate>(_material.Data()))
{
}

//////////////////////////////////////////////////
Material::Material(Material &&_material) noexcept
  : dataPtr(std::move(_material.dataPtr))
{
}

//////////////////////////////////////////////////
Material &Material::operator=(Material &&_material)
{
  this->dataPtr = std::move(_material.dataPtr);
  return *this;
}

//////////////////////////////////////////////////
Material &Material::operator=(const Material &_material)
{
  this->dataPtr->material = _material.Data();
  return *this;
}

//////////////////////////////////////////////////
const sdf::Material &Material::Data() const
{
  return this->dataPtr->material;
}
