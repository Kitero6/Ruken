/*
 *  MIT License
 *
 *  Copyright (c) 2019 Basile Combet, Philippe Yi
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NON INFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include "Resource/ResourceManager.hpp"

USING_DAEMON_NAMESPACE

ResourceManifest* ResourceManager::RequestManifest(ResourceIdentifier const& in_unique_identifier) noexcept
{
	ManifestsWriteAccess access(m_manifests);

	// If there is no such manifest in the map: adding a new one
	if (access->find(in_unique_identifier) != access->end())
		return access.Get()[in_unique_identifier];

	// Creating a new invalid manifest.
	ResourceManifest* manifest = new ResourceManifest();
	access.Get()[in_unique_identifier] = manifest;

	return manifest;
}

ResourceManager::ResourceManager() noexcept:
	m_manifests			{},
	m_collection_mode	{EGCCollectionMode::Automatic}
{}

ResourceManager::~ResourceManager() noexcept
{
	// If the resource manager is destroyed, we need to make sure
	// that all resources are correctly deleted from memory to avoid leaks
	//FlushResources();
}
